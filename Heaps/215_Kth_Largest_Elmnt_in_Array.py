class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        maxHeap = []

        for num in nums:
            heapq.heappush(maxHeap, -1*num)
        
        for _ in range(k):
            kth_largest = heapq.heappop(maxHeap)
        
        return -1 * kth_largest
