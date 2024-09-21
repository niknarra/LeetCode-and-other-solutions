'''
# Node Class
	class Node:
	    def __init__(self, data):   # data -> value stored in node
	        self.data = data
	        self.next = None
	        self.prev = None
'''

class Solution:
    #Function to delete all the occurances of a key from the linked list.
    def deleteAllOccurOfX(self, head, x):
        # code here
        
        if head is None:
            return None
        
        while head is not None and head.data == x:
            head = head.next
            if head is not None:
                head.prev = None
            
        curr = head
          
        while curr is not None:
            if curr.data == x:
                back = curr.prev
                front = curr.next
                
                back.next = front
                
                if front is not None:
                    front.prev = back
                
                curr = curr.next
                
            else:
                curr = curr.next
        
        return head

