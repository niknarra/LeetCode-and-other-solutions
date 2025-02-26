class Solution:
    def maxSum(self, grid: List[List[int]], limits: List[int], k: int) -> int:
        if k == 0:
            return 0
        
        minHeap = []
        row, col = len(grid), len(grid[0])

        for i in range(row):
            grid[i].sort(reverse = True)
            for j in range(min(limits[i], len(grid[i]))):
                heapq.heappush(minHeap, grid[i][j])
            
            while len(minHeap) > k:
                heapq.heappop(minHeap)
        
        return sum(minHeap)
