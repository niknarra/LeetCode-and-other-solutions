# No sorting - O(n) Approach

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        i = max(nums)
        nums.remove(i)

        j = max(nums)
        nums.remove(j)

        return (i-1) * (j-1)

# With Sorting - O(n log n) Approach

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        nums.sort(reverse=True)

        return (nums[0]-1) * (nums[1]-1)
