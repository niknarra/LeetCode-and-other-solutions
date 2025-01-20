class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        ans = float('-inf')

        for st in strs:
            if st.isdigit():
                ans = max(ans, int(st))
            else:
                ans = max(ans, len(st))    

        return ans
