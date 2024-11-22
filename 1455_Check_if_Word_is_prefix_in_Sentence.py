# Initial Approach

class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = sentence.split(' ')

        for index, word in enumerate(words):
            if str(word[0:len(searchWord)]) == searchWord:
                return index+1

        return -1

# Pythony Approach
# startswith function

class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = sentence.split(' ')

        for index, word in enumerate(words):
            if word.startswith(searchWord):
                return index+1

        return -1
