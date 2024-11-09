# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def pushAll(self, root):
        if root is None:
            return
        while root != None:
            self.st.append(root)
            root = root.left

    def __init__(self, root: Optional[TreeNode]):
        self.st = []
        self.pushAll(root)

    def next(self) -> int:
        temp = self.st[-1]
        self.st.pop(-1)
        self.pushAll(temp.right)
        return temp.val

    def hasNext(self) -> bool:
        return not len(self.st) == 0


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
