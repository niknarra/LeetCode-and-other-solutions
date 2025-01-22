# Approach 1 - n log n - no heap approach

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        if len(stones) < 2:
            return 1

        while len(stones) >=2 :
            stones.sort(reverse=True)
            if stones[0] == stones[1]:
                stones = stones[2:]
            elif stones[0] != stones[1]:
                stones[0] = stones[0]-stones[1]
                stones.remove(stones[1])
            
            print(stones)
        
        return stones[0] if stones else 0

# Approach 2 - w/Heap

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        if len(stones) < 2:
            return 1
	# Create a maxHeap
        maxHeap = [-stone for stone in stones]
        heapq.heapify(maxHeap)
        
	# While there are atleast 2 stones
        while len(maxHeap) >= 2:
            y = -1 * heapq.heappop(maxHeap) # Get the first biggest stone
            x = -1 * heapq.heappop(maxHeap) # And the second
	
	# If the two stones are of diff weights
            if x != y:
                y -= x # Get the new stone weight
                
                heapq.heappush(maxHeap, -1*y) # Push to the heap
        
        return -maxHeap[0] if maxHeap else 0 # Return the final stone if there is one, else 0

