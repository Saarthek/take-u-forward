/*
This code is a solution of the problem Climb Stairs from leetcode at the link
https://leetcode.com/problems/climbing-stairs/
The solution progresses from brute force to optimal
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:  
    //Recursion
    /*int climbStairs(int n) {
        if(n<=1){
            // This shows that we reached the end showing that the current recursion stack shows a possible sollution
            return 1;
        }
        else{
            return climbStairs(n-1)+climbStairs(n-2);
        }

    }
    //Time Complexity -> Exponential
    //Space Complexity -> O(n) (Recursion Stack)    
    */
   //Memoization
    int climbStairs(int n) {
        vector <int> dp(n+1, -1);
        int ans = memoizedClimbStairs(n, dp);
        return ans;
    }
    int memoizedClimbStairs(int i, vector<int> & dp){
        if(dp[i]!=-1){
            return dp[i];
        }
        if(i<=1){
            return (dp[i] = 1);
        }
        return (dp[i] = memoizedClimbStairs(i-1, dp) + memoizedClimbStairs(i-2, dp));
    }
    //Time Complexity -> O(n)
    //Space Complexity -> O(n) 1D DP array and Recursion Stack
};

int main(){
    Solution sol;
    int n;
    cin >> n;
    int ans = sol.climbStairs(n);
    cout << ans;
    return 0;
}