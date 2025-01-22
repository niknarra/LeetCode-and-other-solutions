# Approach 1 - Arr -> Min Heap -> heappop K times

class Solution:

	def kSmallest(self,arr, k):
		minHeap = []
		ans = []
		
		for num in arr:
		    heapq.heappush(minHeap, num)
	    
	    for _ in range(k):
	        ans.append(heapq.heappop(minHeap))
	    
	    return ans

# Approach 2 - Arr -> Max Heap -> sort and return heap

class Solution:

	def kSmallest(self,arr, k):
		maxHeap = []

		for num in arr:
		    if len(maxHeap) < k:
		        heapq.heappush(maxHeap, -1 * num)
		    elif -1*num > maxHeap[0]:
		        heapq.heappop(maxHeap)
		        heapq.heappush(maxHeap, -1 * num)
	    
	    maxHeap = [-1* val for val in maxHeap]
	    maxHeap.sort()
	    
	    return maxHeap
