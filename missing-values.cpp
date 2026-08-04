/*
Problem: Find Missing Elements
Link: https://leetcode.com/problems/find-missing-elements/

Input Format:
- First line: An integer n, the number of elements.
- Second line: n space-separated integers.

Output Format:
- Print all missing integers in increasing order.
- If there are no missing integers, print nothing

Sample Input:
6
1 2 4 7 8 10

Sample Output:
3 5 6 9
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                for (int miss = nums[i - 1] + 1; miss < nums[i]; miss++) {
                    ans.push_back(miss);
                }
            }
        }
        return ans;
    }
//     Time Complexity: O(n log n + k)
//     - O(n log n) for sorting
//     - O(k) to generate missing numbers, where k is the number of missing elements

// Space Complexity: O(k)
//     - For storing the missing elements
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<int> ans = obj.findMissingElements(nums);
    for (int x : ans) {
        cout << x << " ";
    }
        cout << "\n";
    return 0;
}