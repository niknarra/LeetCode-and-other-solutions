// Sliding Window Approach
// TC: O(n)
// SC: O(1)

class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        
        vowels = {'a','e','i','o','u'}

        left = 0
        count = 0
        ans = 0

        for right in range(0, len(s)):
            if s[right] in vowels:
                count += 1
            
            while right-left+1 > k:
                if s[left] in vowels:
                    count -= 1
                left += 1
            
            ans = max(ans, count)
            
        return ans
