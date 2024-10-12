# Approach 1 - Hashing
# TC and SC : O(n)

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        if (len(s) != len(t)):
            return False

        s_counts = {}
        t_counts = {}

        for char in s:
            s_counts[char] = s_counts.get(char, 0) + 1
        
        for char in t:
            t_counts[char] = t_counts.get(char, 0) + 1

        return s_counts == t_counts

# Approach 2 - Using a single array
# TC: O(n) and SC: O(1)

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        if (len(s) != len(t)):
            return False

        char_counts = [0] * 26

        for i in range(len(s)):
            char_counts[ord(s[i]) - ord('a')] += 1
            char_counts[ord(t[i]) - ord('a')] -= 1

        return all(count == 0 for count in char_counts)

