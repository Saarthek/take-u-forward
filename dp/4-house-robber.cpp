/*
This code is a solution of the problem House Robber from Leetcode at the link
https://leetcode.com/problems/house-robber
The solution progresses from brute force to optimal
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
    //Recursion
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = recRob(nums, 0, n-1);
        return ans;
    }
    int recRob(vector<int>& nums, int st, int end){
        if(st>end){
            return 0;
        }
        return max(nums[st]+recRob(nums, st+2, end), recRob(nums, st+1, end));
    }
    //Time Complexity -> Exponential
    //Space Complexity -> Linear (Stack Space)    
    */
   /*
   //Memoization
   int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = recRob(nums, dp, 0, n-1);
        return ans;
    }
    int recRob(vector<int>& nums, vector<int> &dp, int st, int end){
        if(st>end){
            return 0;
        }
        if(dp[st]!=-1){
            return dp[st];
        }
        int ans = max(nums[st]+recRob(nums, dp, st+2, end), recRob(nums, dp, st+1, end));
        return dp[st] = ans;
    }
    // Time Complexity -> O(n)
    // Space Complexity -> O(n) ( DP Array + Auxiliary Stack Space)
   */
  /*
  //Tabulation
  public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2, 0);
        int ans = dpRob(nums, dp);
        return ans;
    }
    int dpRob(vector<int>& nums, vector<int> &dp){
        int end = nums.size()-1;
        int st = 0;
        dp[end+1] = 0;
        dp[end+2] = 0;
        for(int i = end; i >= st; i--){
            dp[i] = max(nums[i]+dp[i+2], dp[i+1]);
        }
        return dp[st];
    }
    //Time Complexity -> O(n)
    //Space Complexity -> O(n) 
  */
    //Space Optimization
    int rob(vector<int>& nums){
        int end = nums.size()-1;
        int st = 0;
        int nxt1 = 0;
        int nxt2 = 0;
        int temp;
        for(int i = end; i >= st; i--){
            temp = max(nums[i]+nxt2, nxt1);
            nxt2 = nxt1;
            nxt1 = temp;
        }
        return temp;
    }
    //Time Complexity -> O(N)
    //Space Complexity -> O(1)
};

int main(){
    Solution sol;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int ans = sol.rob(nums);
    cout << ans;
    return 0;
}