class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:

        if(len(nums) == 1):
            return nums[0]

        i = 0
        j = k
        curr_sum = sum(nums[:k])
        ans = curr_sum

        while j < len(nums):
            curr_sum += nums[j] - nums[j-k]
            ans = max(curr_sum, ans)
            j += 1
        
        return ans/k
        
