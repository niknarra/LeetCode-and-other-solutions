class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        I = 0
        J = 1
        while J < len(nums):
            if nums[I] == 0:
                if nums[J] != 0:
                    nums[I], nums[J] = nums[J], nums[I]
                    I += 1
                J += 1
            else:
                I += 1
                if J <= I:
                    J = I + 1

