# Approach 1 - Sliding Window

class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        right = 0
        left = 0
        length = 0
        ans = []

        while(right<len(s)):
            ans.append(s[right])

            if(right-left+1 == 3):
                if len(set(ans)) == 3:
                    length += 1
                ans.remove(s[left])
                left += 1
            
            right += 1
        
        return length

# Approach 2 - Slicing, more Pythonic

class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        length = 0

        for i in range(len(s)-2):
            substring = s[i:i+3]
            
            if len(set(substring)) == 3:
                length += 1
        
        return length

