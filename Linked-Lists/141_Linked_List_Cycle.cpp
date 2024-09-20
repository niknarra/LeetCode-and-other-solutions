/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Tortoise and Hare Method
// If there is a loop, tortoise and hare are bound to overlap

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }
        
        if(head->next == nullptr){
            return false;
        }

        ListNode* hare = head;
        ListNode* tortoise = head;

        while(hare!=nullptr && hare->next!=nullptr){
            tortoise = tortoise->next;
            hare = hare->next->next;
            if(hare == tortoise){
                return true;
            }
        }
        return false;
    }
};
