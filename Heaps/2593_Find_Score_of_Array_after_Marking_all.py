class Solution:
    def findScore(self, nums: List[int]) -> int:
        score = 0
        minHeap = [(num, i) for i, num in enumerate(nums)]
        heapq.heapify(minHeap)

        marked = set()

        while len(marked) < len(nums):
            smallest = heapq.heappop(minHeap)
            num, index = smallest  # Extract value and index
            
            if index not in marked:  # Only process if index is not marked
                marked.add(index)
                score += num  

                # Mark left neighbor
                if index - 1 >= 0 and index - 1 not in marked:
                    marked.add(index - 1)

                # Mark right neighbor
                if index + 1 < len(nums) and index + 1 not in marked:
                    marked.add(index + 1)

        return score
