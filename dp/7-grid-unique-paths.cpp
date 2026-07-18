/*
This code is a solution of the problem Unique Path in grid from Leetcode at the link
https://leetcode.com/problems/unique-paths/description/
The solution progresses from brute force to optimal
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
/*
    //Recursion
private:
    int reqUniquePaths(int i, int j, int m, int n){
        if(i==m&&j==n){
            return 1;
        }
        if(i>m||j>n){
            return 0;
        }
        return (reqUniquePaths(i+1, j, m, n) + reqUniquePaths(i, j+1, m, n));
    }
public:
    int uniquePaths(int m, int n) {
        int ans = reqUniquePaths(0, 0, m-1, n-1);
        return ans;
    }
//Time Complexity -> Exponential
//Space Complexity -> O(m*n) (Auxiliary Stack space)
*/
/*
//Memoization
private:
    int reqUniquePaths(int i, int j, vector<vector<int>> & dp, int m, int n){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==m&&j==n){
            return dp[i][j] = 1;
        }
        if(i>m||j>n){
            return dp[i][j] = 0;
        }
        return dp[i][j] = (reqUniquePaths(i+1, j, dp, m, n) + reqUniquePaths(i, j+1, dp, m, n));
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        int ans = reqUniquePaths(0, 0, dp, m-1, n-1);
        return ans;
    }
//Time Complexity -> O(m*n)
//Space Complexity -> O(m*n) (Stack Space+DP Array)
*/
/*
//Tabulation
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        dp[m-1][n-1] = 1;
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i!=m-1||j!=n-1)
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
//Time Complexity -> O(m*n)
//Space Complexity -> O(m*n) (DP Array)
*/
//Space Optimized
public:
    int uniquePaths(int m, int n) {
        vector<int> next(n+1, 0);
        vector<int> curr(n+1, 0);
        next[n-1] = 1;
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                curr[j] = next[j] + curr[j+1];
            }
            next = curr;
        }
        return curr[0];
    }
//Time Complexity -> O(m*n)
//Space Complexity -> O(n) (curr and next Arrays)
};

int main(){
    int m, n;
    cin >> m >> n;
    Solution sol = Solution();
    int ans = sol.uniquePaths(m, n);
    cout << ans << '\n';
    return 0;
}