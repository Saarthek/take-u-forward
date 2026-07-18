/*
This code is a solution of the problem Unique Path with obstacles in grid from Leetcode at the link
https://leetcode.com/problems/unique-paths-ii/description/
The solution progresses from brute force to optimal
*/

#include <bits/stdc++.h>

using namespace std;

#define MODVAL (int)(2e+9)

class Solution {
/*
    //Recursion
private:
    int reqUniquePath(vector<vector<int>>& obs, int i, int j, int m, int n){
        if(i>m||j>n||obs[i][j]){
            return 0;
        }
        if(i==m&&j==n){
            return 1;
        }
        return (reqUniquePath(obs, i+1, j, m, n)%MODVAL + reqUniquePath(obs, i, j+1, m, n)%MODVAL)%MODVAL;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return reqUniquePath(obstacleGrid, 0, 0, m-1, n-1);
    }
//Time Complexity -> Exponential
//Space Complexity -> O(m*n)
*/
//Memoization
private:
    int reqUniquePath(vector<vector<int>>& obs, int i, int j, vector<vector<int>>& dp, int m, int n){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i>m||j>n||obs[i][j]){
            return dp[i][j]=0;
        }
        if(i==m&&j==n){
            return dp[i][j]=1;
        }
        return  dp[i][j] = (reqUniquePath(obs, i+1, j, dp, m, n) % MODVAL  + reqUniquePath(obs, i, j+1, dp, m, n) % MODVAL) % MODVAL;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        dp[m-1][n-1] = dp[m-1][n-1];
        return reqUniquePath(obstacleGrid, 0, 0, dp, m-1, n-1);
    }
//Time Complexity -> O(m*n)
//Space Complexity -> O(m*n) (DP Array + Auxiliary Stack Space)
};

int main(){
    int m, n;
    cin >> m >> n;
    Solution sol;
    vector<vector<int>> obs(m, vector<int> (n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> obs[i][j];
        }
    }
    int ans = sol.uniquePathsWithObstacles(obs);
    cout << ans << "\n";
    return 0;
}