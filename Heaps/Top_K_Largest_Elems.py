# Approach 1 - Arr -> Max Heap -> Pop K times
# TC: O(n log n); SC: O(n)

class Solution:

	def kLargest(self,arr, k):
		maxHeap = []
		ans = []
		
		for num in arr:
		    heapq.heappush(maxHeap, -1 * num)
		   
		for _ in range(k):
		    ans.append((-1 * heapq.heappop(maxHeap)))
		
		return ans

# Approach 2 - Arr -> Min Heap of size K -> return heap elems
# TC:(K log n); SC: O(k)

class Solution:

	def kLargest(self,arr, k):
		minHeap = []	
		for num in arr:
		    if len(minHeap) < k:
		        heapq.heappush(minHeap, num)
		    elif (minHeap[0]) < num:
		        heapq.heappop(minHeap)
		        heapq.heappush(minHeap,num)
        
	    minHeap.sort(reverse=True)
	    
	    return minHeap
