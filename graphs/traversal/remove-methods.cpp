/*
Problem: Remove Methods From Project
Link: https://leetcode.com/problems/remove-methods-from-project/

Input Format:
n
k
m                       // Number of invocations
u1 v1
u2 v2
...
um vm

where each invocation [u, v] means method u invokes method v.

Output Format:
Indices of the remaining methods separated by spaces.

Example:
Input:
4
1
3
1 2
0 1
3 2

Output:
0 1 2 3

Approach:
- Build the original graph and its reverse graph.
- Perform BFS from the suspicious method k to mark all suspicious methods.
- Traverse the reverse graph starting from suspicious methods.
- If a non-suspicious method can reach a suspicious one, no methods are removed.
- Otherwise, remove all suspicious methods and return the remaining ones.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> g(n);
        vector<vector<int>> revg(n);
        for (vector<int> e : invocations) {
            g[e[0]].push_back(e[1]);
            revg[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n, false);
        queue<int> q, q2;
        q.push(k);
        q2.push(k);
        while (!q.empty()) {
            int tp = q.front();
            q.pop();
            vis[tp] = true;
            for (int nbr : g[tp]) {
                if (!vis[nbr]) {
                    q.push(nbr);
                    q2.push(nbr);
                }
            }
        }
        bool keepAll = false;
        while (!q2.empty()) {
            int tp = q2.front();
            q2.pop();
            if (!vis[tp]) {
                keepAll = true;
                break;
            }
            vis[tp] = true;
            for (int nbr : revg[tp]) {
                if (!vis[nbr]) {
                    q2.push(nbr);
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (keepAll || !vis[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    int n, k, m;
    cin >> n;
    cin >> k;
    cin >> m;
    vector<vector<int>> invocations(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> invocations[i][0] >> invocations[i][1];
    }
    Solution sol;
    vector<int> ans = sol.remainingMethods(n, k, invocations);
    for (int method : ans) {
        cout << method << " ";
    }
    cout << '\n';
    return 0;
}