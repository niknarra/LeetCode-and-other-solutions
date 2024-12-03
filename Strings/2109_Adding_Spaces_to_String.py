# Approach 1 - Using a Set for lookup
# TC: O(m + n) -> m for constructing the set

class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        ans = []
        spaces_set = set(spaces)
        for index, char in enumerate(s):
            if index in spaces_set:
                ans.append(' ')
            ans.append(char)
        
        return ''.join(ans)

# Approach 2 - Using a index pointer
# TC: O(n)

class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        ans = []
        curr = 0
        for index, char in enumerate(s):
            if curr < len(spaces) and index == spaces[curr]:
                ans.append(' ')
                curr += 1
            ans.append(char)
        
        return ''.join(ans)
