/*
    Problem: Subsets
    Link: https://leetcode.com/problems/subsets/
    Input:
        n followed by n elements -> nums array
    Output:
        All possible subsets of nums
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        int numSubs = 1 << n;
        for(int i = 0; i < numSubs; i++){
            vector<int> curr;
            for(int j = 0; j < n; j++){
                if(i & 1 << j){
                    curr.push_back(nums[j]);
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
    // Time Complexity: O(n * 2^n)
    // Space Complexity: O(n * 2^n)
};
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    Solution sol;
    vector<vector<int>> ans = sol.subsets(nums);
    for(const auto& subset : ans){
        cout << "[ ";
        for(int x : subset){
            cout << x << " ";
        }
        cout << "]\n";
    }
    return 0;
}