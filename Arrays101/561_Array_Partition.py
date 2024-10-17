class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort() # Sort the numbers
        sum = 0 
        for i in range(0,len(nums),2): # As the nums are sorted, the minimum value of each pair will be the first element - so inc by 2
            sum += nums[i] # Accumulate the sum 
        
        return sum # Return it
