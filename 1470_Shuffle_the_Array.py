class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        ans = []

        i = 0
        j = n

        while(i<n and j<n*2):
            ans.append(nums[i])
            ans.append(nums[j])

            i+=1
            j+=1

        return ans


