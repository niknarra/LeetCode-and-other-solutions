class Solution:
    def connectSticks(self, sticks: List[int]) -> int:
        cost = 0
        
        minHeap = [stick for stick in sticks]
        heapq.heapify(minHeap)
        
        while len(minHeap) > 1:
            x = heapq.heappop(minHeap)
            y = heapq.heappop(minHeap)
            
            cost += (x + y)
            
            heapq.heappush(minHeap, x+y)
        
        return cost
