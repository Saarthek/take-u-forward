/*
This code is a solution of the problem Frog Jump from Geeks for Geeks at the link
https://www.geeksforgeeks.org/problems/geek-jump/1
The solution progresses from brute force to optimal
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    //Recursion
  /*public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        int ans = auxMinCost(height, 0, n-1);
        return ans;
    }
    int auxMinCost(vector<int> &height, int st, int end){
        if(st>=end){
            return 0;
        }
        int j1 = abs(height[st+1]-height[st]) + auxMinCost(height, st+1, end);
        int j2 = INT_MAX;
        if(st<end-1){
            j2 = abs(height[st+2]-height[st]) + auxMinCost(height, st+2, end);
        }
        return min(j1, j2);
    }
   //Time Complexity -> Exponential
   //Space Complexity -> Linear (Recursion stack)
   */
   //Memoization
   /*private:
    int auxMinCost(vector<int> &height, vector<int> &dp, int st, int end){
        if(dp[st]!=-1){
            return dp[st];
        }
        if(st>=end){
            return dp[st]=0;
        }
        int j1 = abs(height[st+1]-height[st]) + auxMinCost(height, dp, st+1, end);
        int j2 = INT_MAX;
        if(st<end-1){
            j2 = abs(height[st+2]-height[st]) + auxMinCost(height, dp, st+2, end);
        }
        return dp[st]=min(j1, j2);
    }
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n, -1);
        int ans = auxMinCost(height, dp, 0, n-1);
        return ans;
    }
    //Time Complexity -> O(n)
    //Space Complexity -> O(n) Recursion Stack + 1D DP
    */
   //Tabulation
   /*public:
   int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n, -1);
        dp[n-1] = 0;
        for(int i = n-2; i >= 0; i--){
            dp[i] = abs(height[i+1]-height[i]) + dp[i+1];
            if(i<n-2){
                dp[i] = min(dp[i], (abs(height[i+2]-height[i]) + dp[i+2]));
            }
        }
        return dp[0];
    }
    //Time Complexity -> O(n)
    //Space Complexity -> O(n) 1D DP
    */
   //Space Optimized
   public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        //vector<int> dp(n, -1);
        int nxt1 = 0;
        int nxt2 = 0;
        int curr = 0;
        for(int i = n-2; i >= 0; i--){
            //dp[i] = abs(height[i+1]-height[i]) + dp[i+1];
            curr = abs(height[i+1]-height[i]) + nxt1;
            if(i<n-2){
                //dp[i] = min(dp[i], (abs(height[i+2]-height[i]) + dp[i+2]));
                curr = min(curr, abs(height[i+2]-height[i]) + nxt2);
            }
            nxt2 = nxt1;
            nxt1 = curr;
        }
        return curr;
    }
    //Time Complexity -> O(n)
    //Space Complexity -> O(1)
};

int main(){
    Solution sol;
    int n;
    cin >> n;
    vector<int> heights(n);
    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }
    int ans = sol.minCost(heights);
    cout << ans;
    return 0;
}