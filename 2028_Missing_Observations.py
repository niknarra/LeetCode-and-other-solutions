class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        missing = []
        total_length = len(rolls) + n
        total_sum = total_length * mean
        current_sum = sum(rolls)
        missing_sum = total_sum - current_sum

        if (6*n) < missing_sum or (1*n) > missing_sum:
            return []

        if missing_sum >= (1*n) and missing_sum <= (6*n):
            min_sum = 1*n
            max_sum = 6*n

            base = missing_sum // n
            rem = missing_sum % n

            missing = [base] * n

            for i in range(rem):
                missing[i] += 1

            return missing

        return missing
