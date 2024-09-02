class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        round_cost = sum(chalk)
        rem = k%round_cost

        for i in range(0, len(chalk)):
            rem -= chalk[i]
            if rem < 0:
                return i

