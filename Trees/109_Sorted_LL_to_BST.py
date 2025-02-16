class Solution:
    def getMiddle(self, head):
        tortoise = head
        hare = head
        prev = None

        while hare is not None and hare.next is not None:
            hare = hare.next.next
            prev = tortoise
            tortoise = tortoise.next
        
        return prev

    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        # Base case: empty list or single node
        if head is None:
            return None
        if head.next is None:
            return TreeNode(head.val)
        
        # Find the middle node and split the list
        prev = self.getMiddle(head)
        middle = prev.next
        root = TreeNode(middle.val)  # Create the root of the BST

        # Disconnect the left half
        prev.next = None
        leftHalf = head
        rightHalf = middle.next

        # Recursively build the left and right subtrees
        root.left = self.sortedListToBST(leftHalf)
        root.right = self.sortedListToBST(rightHalf)

        return root
