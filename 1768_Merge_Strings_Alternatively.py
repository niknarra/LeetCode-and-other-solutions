# Approch 1
# Here we use ans as a string and append characters to it
# But everytime we append we are essentially creating new strings which can be inefficient

class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        ans = ""
        i = 0
        j = 0

        while(i < len(word1) and j < len(word2)):
            ans += word1[i] + word2[j]
            i += 1
            j += 1
        
        if(i < len(word1)):
            ans += word1[i:]
        
        if(j < len(word2)):
            ans += word2[j:]
        
        return ans

# Approach 2
# We use a list and later join the elements to form a string and return it

class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        ans = []

        for c1, c2 in zip(word1, word2):
            ans.append(c1)
            ans.append(c2)
        
        ans.append(word1[len(word2):] or word2[len(word1):])
        
        return ''.join(ans)

