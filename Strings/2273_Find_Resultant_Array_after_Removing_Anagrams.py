#Approach 1 - Sorting
# O(n * k log k); n-> number of words, k log k -> sorting each word

class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        left = 0
        right = 1
        while right < len(words):
            if sorted(words[left]) == sorted(words[right]):
                words.pop(right)
            else:
                left += 1
                right += 1
        
        return words

# Approach 2 - Counting/Hashing
# O(n*K); k-> time taken to construct a hash after counting character in a word

class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        ans = [words[0]]

        for i in range(1, len(words)):
            if Counter(words[i]) != Counter(ans[-1]):
                ans.append(words[i])
        
        return ans
