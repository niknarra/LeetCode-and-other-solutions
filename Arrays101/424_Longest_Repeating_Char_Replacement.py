# Sliding Window Approach
# TC: O(n)
# SC: O(n)

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        left = 0
        max_count = 0
        counts = {}
        ans = 0

        for right in range(0,len(s)):
	# Store the frequencies of each letter and get the most frequent letter
            counts[s[right]] = counts.get(s[right], 0)+1
            max_count = max(max_count, counts[s[right]])

	# While the size of the window - most frequent letter is greater than k,
	# it means we ran out of replacements, so shrink the window
            while (right-left+1) - max_count > k:
                counts[s[left]] -= 1
                left += 1
            
            ans = max(ans, right-left+1)
        
        return ans
