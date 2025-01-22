import heapq

class Solution:

    def kthSmallest(self, arr,k):
        minHeap = []
        
        for num in arr:
            heapq.heappush(minHeap, num)
        
        for _ in range(k):
            ans = heapq.heappop(minHeap)
        
        return ans

# Or, we can build the heap using heapify function,

import heapq

class Solution:

    def kthSmallest(self, arr, k):
        # Convert array to a heap in O(n) time
        heapq.heapify(arr)
        
        # Extract min k times to get the k-th smallest element
        for _ in range(k):
            ans = heapq.heappop(arr)
        
        return ans

