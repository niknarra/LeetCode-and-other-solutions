class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        counts = {}
        n = len(arr)

        for num in arr:
            counts[num] = counts.get(num, 0) + 1

        if len(counts) == 1:
            return 1

        freqs = sorted(counts.values(), reverse=True)
        
        ans = 0
        target_len = n//2

        while target_len > 0:
            target_len -= freqs[ans]
            ans += 1
        
        return ans
