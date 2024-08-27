class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        
        if len(nums) == 2:
            return nums[0]
        elif nums[0] == nums[1]:
            return nums [0]
        elif nums[len(nums)-1] == nums[len(nums)-2]:
            return nums[len(nums)-1]
        
        low, high = 1, len(nums)-1
        
        while(low<high):
            mid = (low+high)//2
            count = sum(num <= mid for num in nums)
            
            if count>mid:
                high = mid
            else:
                low = mid + 1
        
        return low
        
        
