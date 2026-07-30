/*
Problem: 3Sum
Link: https://leetcode.com/problems/3sum/

Input:
    nums - An integer array.

Output:
    Return all unique triplets [nums[i], nums[j], nums[k]]
    such that:
        - i != j, i != k, j != k
        - nums[i] + nums[j] + nums[k] == 0

Approach:
    1. Sort the array.
    2. Fix one element at a time.
    3. Use the two-pointer technique to find the remaining two elements.
    4. Skip duplicate values to avoid duplicate triplets.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            if (nums[i] > 0)
                break;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    k--;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
                else if (sum < 0) {
                    j++;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                }
                else {
                    k--;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> ans = obj.threeSum(nums);

    cout << "Unique Triplets:\n";
    for (const auto &triplet : ans) {
        cout << "[ ";
        for (int x : triplet)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}

/*
Time Complexity: O(n²)
Space Complexity: O(1) excluding the output vector.
*/