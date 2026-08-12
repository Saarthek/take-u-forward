"""
Problem: Best Time to Buy and Sell Stock
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Input:
- First line: n, the number of days
- Second line: n space-separated integers representing prices

Output:
- Print the maximum profit that can be achieved from one buy and one sell
"""

from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        ans = 0
        currmax = 0

        for i in range(n - 1, -1, -1):
            currmax = max(currmax, prices[i])
            ans = max(ans, currmax - prices[i])

        return ans


def main():
    n = int(input())
    prices = list(map(int, input().split()))

    solution = Solution()
    ans = solution.maxProfit(prices)

    print(ans)


if __name__ == "__main__":
    main()