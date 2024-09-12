class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        ans = -1

        nums = set(nums)

        for num in nums:
            if -num in nums:
                ans = max(ans, abs(num))
        
        return ans
