# Initial Approach - minHeap
# O(n log n)

class Solution:
    def getRank(self, num):
        if num == 1:
            return 0
        
        steps = 0
        
        while num != 1:
            if num%2 == 0:
                num = num//2
            else:
                num = (3*num) + 1
            steps += 1
        
        return steps

    def getKth(self, lo: int, hi: int, k: int) -> int:
        rank = []
        
        for num in range(lo, hi+1):
            rank.append((self.getRank(num), num))
        
        heapq.heapify(rank)

        for _ in range(k):
            ans = heapq.heappop(rank)[1]

        return ans

# Optimal Approach without Heap
# O(n log n)

class Solution:
    def __init__(self):
        self.memo = {}

    def getRank(self, num):
        if num == 1:
            return 0
        
        if num in self.memo:
            return self.memo[num]
        
        if num % 2 == 0:
            steps = 1 + self.getRank(num//2)
        
        else:
            steps = 1 + self.getRank((3*num) + 1)
        
        self.memo[num] = steps
        return steps

    def getKth(self, lo: int, hi: int, k: int) -> int:
        rank = []
        
        for num in range(lo, hi+1):
            rank.append((self.getRank(num), num))
        
        rank.sort()

        return rank[k-1][1]
