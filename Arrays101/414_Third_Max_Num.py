# Optimal Approach
# TC: O(n)
# SC: O(n)

class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        # Early exit condition
	if len(nums) == 1:
            return nums[0]
        
	# Make a set to get unique elements
        nums_set = set(nums)

	# If the number of unique elements are less than 3, we return the max element and exit 
        if len(nums_set) < 3:
            return max(nums_set)
        
	# If not, we remove the max element twice to get the third maximum element
        nums_set.remove(max(nums_set))
        nums_set.remove(max(nums_set))

        return max(nums_set)
        
