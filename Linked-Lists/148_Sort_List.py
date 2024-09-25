# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def getMiddle(self, head): # Function to find out the middle node

        if head is None or head.next is None:
            return head

        slow = head # Using the two pointer approach
        fast = head.next # We set head.next to ensure that we're getting the first head in case of even lengths

        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next

        return slow # Return the middle node
    
    def merge(self, left, right): # Function to merge the two sorted lists

        dummy = ListNode(-1) # Initialize a dummy node to build the LL
        temp = dummy

        while left is not None and right is not None: # Traverse through the two lists
            if left.val < right.val:
                temp.next = left
                left = left.next
            else:
                temp.next = right
                right = right.next
            temp = temp.next
        
        if left:
            temp.next = left
        
        if right:
            temp.next = right
        
        return dummy.next # Return the head of the sorted LL


    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        if head is None or head.next is None: # Base Case
            return head

        middle = self.getMiddle(head)

        right = middle.next # The right half of the array will be the element after middle node
        middle.next = None # Unlink the left half from the right
        left = head

        left = self.sortList(left) # Sort the left half
        right = self.sortList(right) # Sort the right half

        return self.merge(left,right) # Merge the two sorted halfs and return the new head
        
