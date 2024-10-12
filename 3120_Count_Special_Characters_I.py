class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        word_list = set(word)
        seen = set()
        ans = 0

        for char in word_list:
            if char not in seen:
                if char.islower() and char.upper() in word_list:
                        ans += 1
                elif char.isupper() and char.lower() in word_list:
                        ans += 1
                
                seen.add(char)
                seen.add(char.swapcase())

        return ans
