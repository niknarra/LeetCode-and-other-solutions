# Approach 1 - using Stack

class Solution:
    def maxDepth(self, s: str) -> int:
        st = []
        max_length = 0

        for char in s:
            if char == '(':
                st.append(char)
                max_length = max(max_length, len(st))
            elif char == ')':
                st.pop()
        
        return max_length

# Approach 2 - without using stack 
# This can be done as we're only using the length and not any stack specific functions

class Solution:
    def maxDepth(self, s: str) -> int:
        max_depth = 0
        current_depth = 0

        for char in s:
            if char == '(':
                current_depth += 1
                max_depth = max(max_depth, current_depth)
            elif char == ')':
                current_depth -= 1
        
        return max_depth

