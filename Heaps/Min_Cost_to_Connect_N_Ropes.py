import heapq
class Solution:
    #Function to return the minimum cost of connecting the ropes.
   def minCost(self, arr: list[int]) -> int:
    
        minHeap = [num for num in arr]
        heapq.heapify(minHeap)
        
        cost = 0
        
        while len(minHeap) > 1:
            x = heapq.heappop(minHeap)
            y = heapq.heappop(minHeap)
            
            cost += (x+y)
                
            heapq.heappush(minHeap, x+y)
        
        return cost
