# TC: O(n)
# SC: O(1)

class Solution:
    def findNonMinOrMax(self, nums: List[int]) -> int:
        if len(nums) <= 2:
            return -1
        
        min_val = min(nums)
        max_val = max(nums)

        for num in nums:
            if num != min_val and num != max_val:
                return num

