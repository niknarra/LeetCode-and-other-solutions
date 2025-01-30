# Approach 1 - maxHeap

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        if len(nums) == 1:
            return nums

        freq = {}
        minHeap = []

        for num in nums:
            freq[num] = freq.get(num, 0) + 1
        
        for count in freq:
            heapq.heappush(minHeap, (-freq[count], count))
        
        ans = [heapq.heappop(minHeap)[1] for _ in range(k)]
        
        return ans

# Approach 2 - minHeap of size K

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        if len(nums) == 1:
            return nums

        freq = {}
        minHeap = []

        for num in nums:
            freq[num] = freq.get(num, 0) + 1
        
        for num in freq:
            heapq.heappush(minHeap, (freq[num], num))
            if len(minHeap) > k:
                heapq.heappop(minHeap)
        
        ans = [heapq.heappop(minHeap)[1] for _ in range(k)]
        
        return ans
