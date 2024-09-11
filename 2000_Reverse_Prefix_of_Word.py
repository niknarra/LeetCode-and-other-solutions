# Approach 1 - Using For Loop

class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        if ch not in word or len(word) == 1:
            return word
        
        for i in range(0,len(word)):
            if word[i] == ch:
                flip_index = i
                break
        
        to_be_reversed = word[0:flip_index+1][::-1]

        return to_be_reversed+word[flip_index+1:]

# Approach 2 - Using .index() list method

class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        try:
            flip_index = word.index(ch)
        except ValueError:
            return word
        
        to_be_reversed = word[0:flip_index+1][::-1]

        return to_be_reversed + word[flip_index+1:]

# TC of both - O(n)
