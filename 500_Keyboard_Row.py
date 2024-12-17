class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        ans = []

        row1 = set("qwertyuiop")
        row2 = set("asdfghjkl")
        row3 = set("zxcvbnm")

        for word in words:
            chars = set(word.lower())
            if chars <= row1 or chars <= row2 or chars <= row3:
                ans.append(word)
        
        return ans
