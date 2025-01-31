class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False
        
        counts = {}

        for num in hand:
            counts[num] = counts.get(num, 0) + 1
        
        minHeap = list(counts.keys())
        heapq.heapify(minHeap)

        while minHeap:
            first = minHeap[0]

            for i in range(first, first+groupSize):
                if i not in counts:
                    return False
                
                counts[i] -= 1
                if counts[i] == 0:
                    if i != minHeap[0]:
                        return False
                    heapq.heappop(minHeap)
        
        return True

