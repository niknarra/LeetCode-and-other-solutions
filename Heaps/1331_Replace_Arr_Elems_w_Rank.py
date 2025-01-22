# Can be done w/o heap as well
# TC: O(n log n); SC: O(n)

class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        minHeap = []
        ranks = {}

        N = len(arr)

        for num in arr:
            heapq.heappush(minHeap, num)

        rank = 1

        for _ in range(N):
            curr = heapq.heappop(minHeap)
            if curr not in ranks:
                ranks[curr] = rank
                rank += 1

        for i in range(N):
            arr[i] = ranks[arr[i]]

        return arr

