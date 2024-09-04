class Solution:
    def getLucky(self, s: str, k: int) -> int:
        digits = []
        tot_sum = 0
        for char in s:
            if (ord(char)-96) >= 10:
                digits.extend([int(digit) for digit in str((ord(char)-96))])
            else:
                digits.append(ord(char) - 96)
        
        while k>0:
            tot_sum = sum(digits)
            digits = [int(digit) for digit in str(tot_sum)]
            k -= 1

        return tot_sum
