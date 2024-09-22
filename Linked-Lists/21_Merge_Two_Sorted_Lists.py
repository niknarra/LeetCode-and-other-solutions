# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        t1 = list1
        t2 = list2

        dummy = ListNode(-1)
        curr = dummy

        while t1 is not None and t2 is not None:
            if t1.val < t2.val:
                curr.next = t1
                t1 = t1.next
            else:
                curr.next = t2
                t2 = t2.next
            
            curr = curr.next
        
        if t1 is not None:
            curr.next = t1
        elif t2 is not None:
            curr.next = t2
        
        return dummy.next
        
