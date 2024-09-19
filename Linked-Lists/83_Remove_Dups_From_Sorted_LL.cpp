/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr){ // Check if list is empty
            return nullptr; // Return nullptr and exit
        }
        
        if(head->next == nullptr){ // Check if list has only one node
            return head; // Return head and exit
        }

        ListNode* curr = head->next; // Set a node to be at the 2nd element initially
        ListNode* prev = head; // Set the prev node to be at head (1st element)

        while(curr!=nullptr){ // While current is not nullptr
            if(prev->val == curr->val){ // check if prev and curr both nodes have same value
                ListNode* temp = curr; // Then create a temp node to hold curr
                prev->next = curr->next; // Chain the previous node and the node after curr node
                curr = curr->next; // Move curr to next node
                delete temp; // Free the memory by deleting temp node
            }else{
	    prev = curr; // If not, move prev by 1
	    curr = curr->next; // And curr by 1
            }
	}
 
       return head; // Return head
    }
};
