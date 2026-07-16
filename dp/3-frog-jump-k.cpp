/*
This code is a solution of the problem Frog Jump with K distance from atCoder at the link
https://atcoder.jp/contests/dp/tasks/dp_b
The solution progresses from brute force to optimal
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    //Recursion
  public:
    /*int minCost(int k, vector<int>& height) {
        // Code here
        int n = height.size();
        int ans = auxMinCost(height, 0, n-1, k);
        return ans;
    }
    int auxMinCost(vector<int> &height, int st, int end, int k){
        if(st>=end){
            return 0;
        }
        int ans = INT_MAX;
        for(int i = 1; i <= k; i++){
            if(st+i>end){
                break;
            }
            int curr = abs(height[st+i]-height[st]) + auxMinCost(height, st+i, end, k);
            ans = min(ans, curr);
        }
        return ans;
    }*/
   //Time Complexity -> Exponential
   //Space Complexity -> Linear (Recursion stack)
   //Memoization
   /*private:
    int auxMinCost(vector<int> &height, vector<int> &dp, int st, int end, int k){
        if(dp[st]!=-1){
            return dp[st];
        }
        if(st>=end){
            return dp[st]=0;
        }
        int ans = INT_MAX;
        for(int i = 1; i <= k; i++){
            if(st+i > end){
                break;
            }
            int curr = abs(height[st+i]-height[st]) + auxMinCost(height, dp, st+i, end, k);
            ans = min(curr, ans);
        }
        return dp[st]=ans;
    }
  public:
    int minCost(int k, vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n, -1);
        int ans = auxMinCost(height, dp, 0, n-1, k);
        return ans;
    }
    //Time Complexity -> O(n)
    //Space Complexity -> O(n) Recursion Stack + 1D DP
    */
   //Tabulation
   public:
   int minCost(int k, vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n, INT_MAX);
        dp[n-1] = 0;
        for(int i = n-2; i >= 0; i--){
            for(int j = 1; j <= k && i+j<n; j++){
                dp[i] = min(dp[i], (abs(height[i+j]-height[i]) + dp[i+j]));
            }
        }
        return dp[0];
    }
    //Time Complexity -> O(n)
    //Space Complexity -> O(n) 1D DP
};

int main(){
    Solution sol;
    int n;
    int k;
    cin >> n >> k;
    vector<int> heights(n);
    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }
    int ans = sol.minCost(k, heights);
    cout << ans;
    return 0;
}