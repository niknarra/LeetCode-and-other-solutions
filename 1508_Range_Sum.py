class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        ans = []

        for i in range(0,len(nums)):
            curr_sum = 0
            for j in range(i,len(nums)):
                curr_sum += nums[j]
                ans.append(curr_sum)

        
        ans.sort()

        range_sum = sum(ans[left-1:right])
        
        return range_sum%1000000007
