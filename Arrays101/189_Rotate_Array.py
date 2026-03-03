class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def reverser(nums, start, end):
            while start < end:
                nums[start], nums[end] = nums[end], nums[start]
                start += 1
                end -= 1

        k = k % len(nums)

        if k != 0:
            nums.reverse()
            reverser(nums, 0, k-1)
            reverser(nums, k, len(nums)-1)
        
