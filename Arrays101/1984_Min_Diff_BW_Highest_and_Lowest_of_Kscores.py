class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:

        if k == 1:
            return 0

        nums.sort()
        ans = float('inf')

        for i in range(0,len(nums)-k+1):
            j = i+k-1
            ans = min(nums[j] - nums[i], ans)

        return ans

