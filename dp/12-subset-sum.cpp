#include <bits/stdc++.h>

using namespace std;

class Solution {
//Memoization
  private:
    int recSubsetSum(vector<int>& arr, vector<vector<int>> & dp, int sum, int st, int end){
        if(dp[sum][st]!=-1){
            return dp[sum][st];
        }
        if(sum==0){
            return dp[sum][st]=true;
        }
        if(sum!=arr[st]&&st==end){
            return dp[sum][st] = false;
        }
        dp[sum][st] = false;
        if(sum-arr[st]>=0){
            dp[sum][st] = recSubsetSum(arr, dp, sum-arr[st], st+1, end);
        }
        return dp[sum][st] = dp[sum][st] || recSubsetSum(arr, dp, sum, st+1, end);
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(sum+1, vector<int>(n+1, -1));
        return recSubsetSum(arr, dp, sum, 0, n-1);
    }
//Time Complexity -> O(n)
//Space Complexit -> O(n)  (Recursion stack + DP array)
};

int main(){
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    Solution sol;
    bool ans = sol.isSubsetSum(arr, sum);
}