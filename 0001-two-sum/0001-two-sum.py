class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        tmp = {}
        for i in range(n):
            remInd = tmp.get(target-nums[i], -1)
            if remInd != -1:
                return [remInd, i]
            tmp[nums[i]] = i
        return []