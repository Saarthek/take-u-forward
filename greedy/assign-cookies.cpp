/*
Problem: Assign Cookies
Link: https://leetcode.com/problems/assign-cookies/

Input Format:
n                      // Number of children
g1 g2 ... gn           // Greed factor of each child
m                      // Number of cookies
s1 s2 ... sm           // Size of each cookie

Output Format:
Maximum number of content children.

Example:
Input:
3
1 2 3
2
1 1

Output:
1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = 0;
        int ng = g.size();
        int ns = s.size();
        for (int i = 0; i < ns && j < ng; i++) {
            if (s[i] >= g[j]) {
                // Assign current cookie to current child
                j++;
            }
        }
        return j;
    }
//Time Complexity: O(n log n + m log m)
//Space Complexity: O(1) (excluding sorting implementation)
};

int main() {
    int n;
    cin >> n;
    vector<int> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    int m;
    cin >> m;
    vector<int> s(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    Solution sol;
    cout << sol.findContentChildren(g, s) << endl;
    return 0;
}