class Solution:
    def getSum(self, num):
        ans = 0

        while num > 0:
            digit = num % 10
            ans += digit
            num //= 10
        
        return ans

    def maximumSum(self, nums: List[int]) -> int:
        sums = defaultdict(list)
        ans = -1

        # sums = [self.getSum(num) for num in nums]

        # for num in nums:
        #     maxHeap.append((-self.getSum(num), -num))
        
        # heapq.heapify(maxHeap)

        for num in nums:
            idx = self.getSum(num)
            
            sums[idx].append(num)
        
        for total in sums:
            values = sorted(sums[total], reverse=True)
            if len(values) >= 2:
                ans = max(ans, values[0]+values[1])

        return ans
