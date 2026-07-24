/*
This code is a solution for the problem named ninja and his friends in take-u-forward but chocolate pickup in geeks-for-geeks
https://www.geeksforgeeks.org/problems/chocolates-pickup/1
I have directly approached from the tabulation approach and Space optimized approach without the recursion and memoization
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
/*
//Tabulation
  public:
    int maxChocolate(vector<vector<int>>& grid) {
        // code here
        vector<int> del1 = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        vector<int> del2 = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int> (m, -1)));
        //dp[0][0][m-1]
        for(int i1 = m-1; i1 >= 0; i1--){
            for(int i2 = m-1; i2 >= 0; i2--){
                if(i1==i2){
                    dp[n-1][i1][i2]=grid[n-1][i1];
                }
                else{
                    dp[n-1][i1][i2] = grid[n-1][i1]+grid[n-1][i2];
                }
            }
        }
        for(int i = n-2; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                for(int k = m-1; k >= 0; k--){
                    int ans = -1;
                    int nnbr = del1.size();
                    for(int ind = 0; ind < nnbr; ind++){
                        int j1 = j+del1[ind];
                        int k1 = k+del2[ind];
                        if(j1>=0&&j1<m&&k1<m&&k1>=0){
                            if(j==k){
                                ans = max(ans, dp[i+1][j1][k1]+grid[i][j]);
                            }
                            else{
                                ans = max(ans, dp[i+1][j1][k1]+grid[i][j]+grid[i][k]);
                            }
                        }
                    }
                    dp[i][j][k] = ans;
                }
            }
        }
        return dp[0][0][m-1];
    }
//Time Complexity -> O(n*m*m)
//Space Complexity -> O(n*m*m)
*/
//Space Optimization
public:
    int maxChocolate(vector<vector<int>>& grid) {
        // code here
        vector<int> del1 = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        vector<int> del2 = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> curr(m, vector<int> (m, -1));
        vector<vector<int>> next(m, vector<int> (m, -1));
        for(int i1 = m-1; i1 >= 0; i1--){
            for(int i2 = m-1; i2 >= 0; i2--){
                if(i1==i2){
                    next[i1][i2] = grid[n-1][i1];
                }
                else{
                    next[i1][i2] = grid[n-1][i1]+grid[n-1][i2];
                }
            }
        }
        for(int i = n-2; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                for(int k = m-1; k >= 0; k--){
                    int ans = -1;
                    int nnbr = del1.size();
                    for(int ind = 0; ind < nnbr; ind++){
                        int j1 = j+del1[ind];
                        int k1 = k+del2[ind];
                        if(j1>=0&&j1<m&&k1<m&&k1>=0){
                            if(j==k){
                                ans = max(ans, next[j1][k1]+grid[i][j]);
                            }
                            else{
                                ans = max(ans, next[j1][k1]+grid[i][j]+grid[i][k]);
                            }
                        }
                    }
                    curr[j][k] = ans;
                }
            }
            swap(next,curr);
        }
        return next[0][m-1];
    }
//Time Complexity -> O(n*m*m)
//Space Complexity -> O(m*m)
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    Solution sol;
    int ans = sol.maxChocolate(arr);
    cout << ans << "\n";
    return 0;
}