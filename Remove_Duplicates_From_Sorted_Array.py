class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 1
        
        i, j = 0, 1

        while (j < len(nums)):
            if nums[i] == nums[j]:
                j += 1
            else:
                nums[i+1] = nums[j]
                j += 1
                i += 1
        
        return i+1
