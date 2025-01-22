# Not the most optimal approach

import heapq

class Solution:
    #Function to merge k sorted arrays.
    def mergeKArrays(self, arr, K):
        # code here
        # return merged list
        minHeap = []
        ans = []
        
        for i in range(K):
            for j in range(K):
                heapq.heappush(minHeap, arr[i][j])
        
        for _ in range(K*K):
            ans.append(heapq.heappop(minHeap))
            
        
        return ans

# Optimal Approach
