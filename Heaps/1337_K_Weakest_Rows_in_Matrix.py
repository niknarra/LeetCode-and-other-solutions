class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        minHeap = []

        for i, row in enumerate(mat):
            soldiers = sum(row)
            heapq.heappush(minHeap, (soldiers, i))
        
        ans = [heapq.heappop(minHeap)[1] for _ in range(k)]

        return ans
