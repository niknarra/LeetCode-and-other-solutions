# Approach 1 - Detailed Checks

class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        if s == "":
            return ""
        
        st = []
        ans = []

        for char in s:
            if not st:
                st.append(char)
            elif char == ')' and st[-1] == '(':
                st.pop()
                if(st):
                    ans.append(char)
            else:
                st.append(char)
                ans.append(char)
        
        return ''.join(ans)

# Approach 2 - Same logic but more polished and broader checks

class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        st = []
        ans = []

        for char in s:
            if char == '(':
                if st:
                    ans.append(char)
                st.append(char)
            
            else:
                st.pop()
                if st:
                    ans.append(char)

        
        return ''.join(ans)

