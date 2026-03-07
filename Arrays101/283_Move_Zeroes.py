class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # i -> finder pointer to iterate to the end
        # lastNonZeroFoundAt -> will always be at index + 1 of last non zero element
        i, lastNonZeroFoundAt = 0, 0
        n = len(nums)

        while i < n:
            # If curr number is non 0
            if nums[i] != 0:
                # Swap it with the most recent index with zero as the value
                # and increment the lastNonZeroFoundAt pointer
                nums[i], nums[lastNonZeroFoundAt] = nums[lastNonZeroFoundAt], nums[i]
                lastNonZeroFoundAt += 1
            # Move our iterator either way
            i += 1
