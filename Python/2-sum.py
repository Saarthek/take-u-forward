"""
Problem: Two Sum
Link: https://leetcode.com/problems/two-sum/

Input:
- First line: n, the size of the array
- Second line: n space-separated integers representing nums
- Third line: target

Output:
- Print the indices of the two elements whose sum equals target
- Print an empty result if no such pair exists
"""

from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        st = 0
        end = n - 1
        tmp = {}

        for i in range(n):
            remInd = tmp.get(target - nums[i], -1)

            if remInd != -1:
                return [remInd, i]

            tmp[nums[i]] = i

        return []


def main():
    n = int(input())
    nums = list(map(int, input().split()))
    target = int(input())

    solution = Solution()
    ans = solution.twoSum(nums, target)

    print(*ans)


if __name__ == "__main__":
    main()