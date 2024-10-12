class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False
        
        vowels = {'a','e','i','o','u'}
        word = word.lower()
        
        vowel = 0
        consonant = 0
        
        for char in word:
            if char.isalpha():
                if char in vowels:
                    vowel += 1
                else:
                    consonant += 1 
            elif char.isdigit():
                continue
            else:
                return False
        
        return vowel>=1 and consonant>=1
