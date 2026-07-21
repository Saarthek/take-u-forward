/*
This code is a solution of the problem Minimum Falling Path Sum from Leetcode at the link
https://leetcode.com/problems/minimum-path-sum/description/
The solution progresses from brute force to optimal
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
/*
//Recursion
private:
    int recMinPathSum(int i, int j, int m, int n, vector<vector<int>>& grid){
        if(i==m&&j==n){
            return grid[i][j];
        }
        if(i>m||j>n){
            return -1;
        }
        int val = -1;
        int fwd = recMinPathSum(i+1, j, m, n, grid);
        int down = recMinPathSum(i, j+1, m, n, grid);
        if(fwd!=-1){
            val = grid[i][j] + fwd;
        }
        if(down!=-1){
            if(val!=-1){
                val = min(val, grid[i][j]+down);
            }
            else{
                val = grid[i][j]+down;
            }
        }
        return val;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return recMinPathSum(0, 0, m-1, n-1, grid);
    }
//Time Complexity -> Exponential
//Space Complexity -> O(m+n) (Recursion stack)
*/
/*
//Memoization
private:
    int recMinPathSum(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==m&&j==n){
            return dp[i][j] = grid[i][j];
        }
        if(i>m||j>n){
            return dp[i][j] = -1;
        }
        int val = -1;
        int fwd = recMinPathSum(i+1, j, m, n, grid, dp);
        int down = recMinPathSum(i, j+1, m, n, grid, dp);
        if(fwd!=-1){
            val = grid[i][j] + fwd;
        }
        if(down!=-1){
            if(val!=-1){
                val = min(val, grid[i][j]+down);
            }
            else{
                val = grid[i][j]+down;
            }
        }
        return dp[i][j]=val;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return recMinPathSum(0, 0, m-1, n-1, grid, dp);
    }
//Time Complexity -> O(m*n)
//Space Complexity -> O(m*n) (Auxiliary Stack space + DP Array)
*/
/*
//Tabulation
private:
    int recMinPathSum(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        dp[m][n] = grid[m][n];
        for(int i = m; i >= 0; i--){
            for(int j = n; j >= 0; j--){
                int fwd = dp[i+1][j];
                int down = dp[i][j+1];
                if(fwd!=-1){
                    dp[i][j] = grid[i][j] + fwd;
                }
                if(down!=-1){
                    if(dp[i][j]!=-1){
                        dp[i][j] = min(dp[i][j], grid[i][j]+down);
                    }
                    else{
                        dp[i][j] = grid[i][j]+down;
                    }
                }
            }
        }
        return dp[0][0];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return recMinPathSum(0, 0, m-1, n-1, grid, dp);
    }
//Time Complexity -> O(m*n)
//Space Complexity -> O(m*n) (DP Array)
*/
//Space Optimization
private:
    int auxMinPathSum(int m, int n, vector<vector<int>>& grid){
        vector<int> next(n+2, -1);
        vector<int> curr(n+2, -1);
        if(m==0&&n==0){
            return grid[m][n];
        }
        next[n] = grid[m][n];
        for(int i = n-1; i >= 0; i--){
            next[i] = next[i+1]+grid[m][i];
        }
        curr = next;
        for(int i = m-1; i >= 0; i--){
            for(int j = n; j >= 0; j--){
                int temp = -1;
                int fwd = next[j];
                if(fwd!=-1){
                    temp = grid[i][j] + fwd;
                }
                int down = curr[j+1];
                if(down!=-1){
                    if(temp!=-1){
                        temp = min(temp, grid[i][j]+down);
                    }
                    else{
                        temp = grid[i][j]+down;
                    }
                }
                curr[j] = temp;
            }
            next = curr;
        }
        return curr[0];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return auxMinPathSum(m-1, n-1, grid);
    }
//Time Complexity -> O(m*n)
//Space complexity -> O(n)
};

int main(){
    Solution sol = Solution();
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int> (n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    int ans = sol.minPathSum(grid);
    cout << ans << "\n";
    return 0;
}