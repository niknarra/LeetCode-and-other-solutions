# Approach 1 - O(n * k)

class Solution:
    def isPalin(self, word):
        i = 0
        j = len(word)-1

        while(i<j):
            if word[i] != word[j]:
                return False
            i+=1
            j-=1
        
        return True
    
    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            if self.isPalin(word):
                return word
        
        return ""

# Approach 2 - O(n * k)

class Solution:
    def isPalin(self, word):
        return word == word[::-1]
    
    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            if self.isPalin(word):
                return word
        
        return ""
