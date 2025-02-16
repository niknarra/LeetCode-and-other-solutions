class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        counts = {}
        time = 0
        q = deque()

        for task in tasks:
            counts[task] = counts.get(task, 0) + 1
        
        maxHeap = [-value for value in counts.values()]
        heapq.heapify(maxHeap)

        while maxHeap or q:
            time += 1

            if maxHeap:
                cnt = 1 + heapq.heappop(maxHeap)

                if cnt:
                    q.append([cnt, time+n])
            
            if q and q[0][1] == time:
                heapq.heappush(maxHeap, q.popleft()[0])
        
        return time
