# Optimal solution
# TC and SC: O(n)

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
	# The dict will store the number and it's index
        pairs = {}
	
	# Using enumerate as we also need the index while returning
        for i, num in enumerate(nums):
	# Check if the difference (pair) for the current number exists in the list
            diff = target - num
	# If it exists, we must've already stored it in our dict so return the current index and the index of the pair
            if diff in pairs:
                return [pairs[diff], i]
        # If it doesn't exist, then push the current num to the dict with the index
            pairs[num] = i

