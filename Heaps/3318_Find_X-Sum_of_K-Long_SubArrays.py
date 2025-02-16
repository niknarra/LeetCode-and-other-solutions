class Solution:
    def getXSum(self, nums, x):
        ans = 0
        maxHeap = []

        counts = Counter(nums)

        if len(counts) < x:
            return sum(nums)

        for count in counts:
            heapq.heappush(maxHeap, (-counts[count], -count))

        for _ in range(x):
            count, val = heapq.heappop(maxHeap)
            ans += (-val*-count)

        return ans

    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        left = 0
        right = k
        ans = []

        while right<=len(nums):
            subArr = nums[left:right]
            print(subArr)
            currXSum = self.getXSum(subArr, x)

            ans.append(currXSum)

            left += 1
            right += 1
        
        return ans
