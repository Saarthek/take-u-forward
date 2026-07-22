#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<int> indeg(n, 0);
        for(int i = 0; i < n; i++){
            for(int j : prereq[i]){
                indeg[j]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        int val = 0;
        while(!q.empty()){
            int i = q.front();
            q.pop();
            val++;
            ans.push_back(i);
            for(int j : prereq[i]){
                indeg[j]--;
                if(indeg[j]==0){
                    q.push(j);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return (val==n);
    } 
};

int main(){
    Solution sol;
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(e, vector<int> (2, 0));
    bool ans = sol.canFinish(n, edges);
    cout << ans << "\n";
    return 0;
}