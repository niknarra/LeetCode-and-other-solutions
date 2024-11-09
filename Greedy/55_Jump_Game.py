class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxIndexReached = 0
        curr = 0
        
        while(curr < len(nums)):

            if curr > maxIndexReached:
                return False

            maxIndexReached = max(maxIndexReached, curr+nums[curr])
            curr += 1
        
        return True
