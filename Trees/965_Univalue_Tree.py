# Approach 1 - DFS
# TC: O(n)
# SC: O(h) h -> height of tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inOrder(self, root, order):
        if root == None:
            return
        
        self.inOrder(root.left, order)
        order.add(root.val)
        self.inOrder(root.right, order)

    def isUnivalTree(self, root: Optional[TreeNode]) -> bool:
        if root == None:
            return True
        
        order = set()

        self.inOrder(root, order)

        return len(order) == 1

# Approach 2 - Recursion

class Solution:
    def isUnivalTree(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        
        if root.left and root.val != root.left.val:
            return False
        
        if root.right and root.val != root.right.val:
            return False
        
        return self.isUnivalTree(root.left) and self.isUnivalTree(root.right)
