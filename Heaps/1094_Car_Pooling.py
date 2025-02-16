class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        curr_cap = 0
        deboard = []

        trips.sort(key=lambda trip: trip[1])

        for trip in trips:
            while deboard and deboard[0][0] <= trip[1]:
                curr_cap -= heapq.heappop(deboard)[1]
            
            curr_cap += trip[0]
            
            if curr_cap > capacity:
                return False

            heapq.heappush(deboard, (trip[2], trip[0]))

        return True
