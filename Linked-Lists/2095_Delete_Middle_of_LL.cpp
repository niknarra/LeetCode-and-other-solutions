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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }

        ListNode* tortoise = head;
        ListNode* hare = head;
        ListNode* prev = nullptr;

        while(hare!=nullptr && hare->next != nullptr){
            hare = hare->next->next;
            prev = tortoise;
            tortoise = tortoise->next;
        }

        prev->next = tortoise->next;
        delete tortoise;

        return head;
    }
};
