class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        cntT = 0
        cntF = 0
        max_len = 0
        left = 0
        right = 0

        while(right<len(answerKey)):
            if answerKey[right] == 'T':
                cntT += 1
            else:
                cntF += 1
            
            while(min(cntT, cntF)>k):
                if answerKey[left] == 'T':
                    cntT -= 1
                else:
                    cntF -= 1
                left += 1
            
            max_len = max(max_len, right-left+1)

            right += 1

        return max_len
