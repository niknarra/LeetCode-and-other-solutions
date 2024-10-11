# Approach 1

class Solution:
    def isValid(self, s: str) -> bool:

        parantheses = {'}':'{',')':'(',']':'['}
        stack = []

        for i in range(0,len(s)):
            if s[i] in parantheses:
                if len(stack) == 0:
                    return False
                elif stack[-1] == parantheses[s[i]]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(s[i])

        return len(stack) == 0

# Approach 2
# Same logic, but more pythonic

class Solution:
    def isValid(self, s: str) -> bool:
        parantheses = {')': '(', '}': '{', ']': '['}
        stack = []

        for char in s:
            if char in parantheses:
                if not stack or stack[-1] != parantheses[char]:
                    return False
                stack.pop()  # Valid pair, pop from stack
            else:
                stack.append(char)  # Open parenthesis, add to stack

        return not stack  # Return True if stack is empty (all matched)

# Both approaches have TC and SC of O(n)

