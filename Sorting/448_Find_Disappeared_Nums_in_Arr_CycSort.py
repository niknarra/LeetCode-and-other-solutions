class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        ans = []
        
        n = len(nums)
        i = 0

        while i < n:
            correct = nums[i] - 1
            if nums[i] <= n and nums[i] != nums[correct]:
                nums[i], nums[correct] = nums[correct], nums[i]
            else:
                i += 1
        
        for i in range(0, n):
            if nums[i] != i+1:
                ans.append(i+1)
        
        return ans
