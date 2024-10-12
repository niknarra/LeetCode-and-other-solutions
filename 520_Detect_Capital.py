# Approach 1 - Pythonic

class Solution:
    def detectCapitalUse(self, word: str) -> bool:

        if len(word) == 1:
            return True

        return word.istitle() or word.isupper() or word.islower()

# Approach 2 - ASCII!
