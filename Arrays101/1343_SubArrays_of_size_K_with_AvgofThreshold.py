# Sliding Window Approach
# TC: O(n)

class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        left = 0
        right = 0
        count = 0
        curr_sum = 0

        while(right<len(arr)):
            curr_sum += arr[right]

            if(right-left+1 == k):
                if(curr_sum//k)>=threshold:
                    count += 1
                curr_sum -= arr[left]
                left += 1
            
            right += 1
        
        return count
