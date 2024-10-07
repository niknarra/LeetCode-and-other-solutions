class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        ans = None
        diff = float('inf')
        for num in nums:
            curr_diff = abs(num)
            if curr_diff < diff:
                diff = curr_diff
                ans = num
            elif curr_diff == diff:
                ans = max(ans, num)
        
        return ans
