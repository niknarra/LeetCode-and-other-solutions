# Approach 1 - Brute Force (DFS->Hash->Max)
# TC: O(4n) SC: O(n)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def dfs(self, root, ans):
        if root is None:
            return
        
        self.dfs(root.left, ans)
        ans.append(root.val)
        self.dfs(root.right, ans)

    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        ans = []

        self.dfs(root, ans)

        if len(ans) == 1:
            return ans

        counts = {}

        for num in ans:
            counts[num] = counts.get(num, 0)+1

        max_count = 0
        mode = []

        for count in counts:
            if counts[count] > max_count:
                max_count = counts[count]
                mode = [count]
            elif counts[count] == max_count:
                mode.append(count)

        return mode

# Approach 2


