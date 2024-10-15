class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        st = []

        for char in s:
            if st and char == ")":
                if st[-1] == "(":
                    st.pop()
                else:
                    st.append(char)
            else:
                st.append(char)

        return len(st)
