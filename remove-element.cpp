/*
Problem: Remove Element (LeetCode 27)
Link: https://leetcode.com/problems/remove-element/

Input:
- nums: A vector of integers.
- val: Integer value to be removed.

Output:
- Returns the number of elements not equal to val after removing all occurrences of val in-place.
- The first k elements of nums should contain the remaining elements (order may change).

Example 1:
Input:
nums = [3,2,2,3]
val = 3

Output:
2

Explanation:
The first two elements of nums become [2,2].

Example 2:
Input:
nums = [0,1,2,2,3,0,4,2]
val = 2

Output:
5

Explanation:
The first five elements of nums contain [0,1,4,0,3] in any order.

Approach:
- Use two pointers:
    - 'st' scans from the beginning.
    - 'end' scans from the end.
- Whenever nums[st] equals val, swap it with a non-val element from the end.
- Shrink the valid range by decrementing end.
- Continue until both pointers meet.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
        int st = 0;
        int end = arr.size() - 1;
        while (st < end) {
            if (arr[st] == val) {
                while (end > st && arr[end] == val) {
                    end--;
                    if (end == st && st == 0) {
                        return 0;
                    }
                }
                swap(arr[st], arr[end]);
                end--;
            }
            st++;
        }
        if (st == end) {
            return st + (arr[end] != val);
        }
        return end + 1;
    }
//Time Complexity -> O(n)
//Space Complexity -> O(1) Transformations on input array as problem statement requires
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int k = sol.removeElement(nums, val);
    cout << "Length after removal: " << k << "\n";
    cout << "Modified array: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}