/*
This code is a solution for the problem named Stone Game III in LeetCode.
https://leetcode.com/problems/stone-game-iii/description/

Input Format:
- The first line contains an integer n, the number of stones.
- The second line contains n space-separated integers representing the values of the stones.

Output Format:
- Print "Alice" if Alice wins.
- Print "Bob" if Bob wins.
- Print "Tie" if both players end with the same score.

Example:
Input:
4
1 2 3 7

Output:
Bob

The code progresses from recursion with memoization.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
//Memoization
private:
    int recPredict(vector<int>& nums, vector<vector<int>>& dp, int st, int end){
        if(dp[st][end] != INT_MIN){
            return dp[st][end];
        }
        if(st > end){
            return dp[st][end] = 0;
        }
        if(st == end){
            return dp[st][end] = nums[st];
        }
        int ans = INT_MIN;
        int acc = 0;
        for(int i = 0; i < 3; i++){
            if(st + i <= end){
                acc += nums[st + i];
                int curr = acc - recPredict(nums, dp, st + i + 1, end);
                ans = max(ans, curr);
            }
            else{
                break;
            }
        }
        return dp[st][end] = ans;
    }

public:
    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MIN));

        int scoreDiff = recPredict(nums, dp, 0, n - 1);

        if(scoreDiff == 0){
            return "Tie";
        }
        else if(scoreDiff > 0){
            return "Alice";
        }

        return "Bob";
    }
//Time Complexity: O(n)
//Space Complexity: O(n^2)
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    Solution sol;
    cout << sol.stoneGameIII(nums) << endl;
    return 0;
}