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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        ListNode* t1 = list1;
        ListNode* t2 = list2;

        while(t1 != nullptr && t2 != nullptr) {
            if(t1->val < t2->val) {
                curr->next = t1;  
                t1 = t1->next;   
            } else {
                curr->next = t2;  
                t2 = t2->next;   
            }
            curr = curr->next;
        }

        if(t1 != nullptr) {
            curr->next = t1;
        } else if(t2 != nullptr) {
            curr->next = t2;
        }

        ListNode* mergedHead = dummy->next;
        delete dummy;

        return mergedHead;
    }
};
