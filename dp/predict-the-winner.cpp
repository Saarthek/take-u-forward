/*
This code is a solution for the problem named Predict the Winner in LeetCode.
https://leetcode.com/problems/predict-the-winner/description/

Input Format:
- An integer array nums.
- nums[i] represents the score associated with the i-th number.
- Two players alternately pick either the leftmost or rightmost number until the array becomes empty.

Output Format:
- Return true if Player 1 can win or tie assuming both players play optimally.
- Otherwise, return false.

LOGIC
    Use currentPlayerScore - OpponentScore as amount used in DP
    dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1])

Example:
Input:
nums = [1, 5, 2]

Output:
false

The code progresses from recursion with memoization.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
/*
//Memoization
private:
    int recPredict(vector<int>& nums, vector<vector<int>>& dp, int st, int end){
        if(dp[st][end]!=-1){
            return dp[st][end];
        }
        if(st>end){
            return dp[st][end] = 0;
        }
        if(st==end){
            return dp[st][end] = nums[st];
        }
        int lft = nums[st] - recPredict(nums, dp, st+1, end);
        int rt = nums[end] - recPredict(nums, dp, st, end-1);
        int ans = max(lft, rt);
        return dp[st][end] = ans;
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n ,vector<int> (n+1, -1));
        int i = 0;
        int j = n-1;
        int res = recPredict(nums, dp, 0, n-1);
        return (res>=0);
    }
//Time Complexity: O(n^2)
//Space Complexity: O(n^2) (Recursion Stack + DP Array)
*/
/*
//Tabulation
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1 ,vector<int> (n+1, 0));
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(i==j){
                    dp[i][i] = nums[i];
                    continue;
                }
                int lft = nums[i] - dp[i+1][j];
                int rt = nums[j] - dp[i][j-1];
                dp[i][j] = max(lft, rt);
            }
        }
        int res = dp[0][n-1];
        return (res>=0);
    }
//Time Complexity: O(n^2)
//Space Complexity: O(n^2) (DP Array)
*/
//Space Optimization
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);
        for(int i = n-1; i >= 0; i--){
            curr[i] = nums[i];
            for(int j = i+1; j < n; j++){
                curr[j] = max(nums[i]-next[j], nums[j]-curr[j-1]);
            }
            next = curr;
        }
        int res = curr[n-1];
        return (res>=0);
    }
//Time Complexity: O(n^2)
//Space Complexity: O(n)
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    bool ans = sol.predictTheWinner(nums);
    cout << boolalpha << ans << endl;
    return 0;
}