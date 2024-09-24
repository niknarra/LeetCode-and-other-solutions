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

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* temp = new ListNode(-1);
        ListNode* dummy = temp;

        while(left!=nullptr && right!=nullptr){
            if(left->val < right->val){
                dummy->next = left;
                left = left->next;
            }
            else{
                dummy->next = right;
                right = right->next;
            }
            dummy = dummy->next;
        }
        if(left){
            dummy->next = left;
        }
        if(right){
            dummy->next = right;
        }
        return temp->next;
    }

    ListNode* middleNode(ListNode* head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* sortList(ListNode* head) {

        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* middle = middleNode(head);
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return merge(left,right);
    }
};
