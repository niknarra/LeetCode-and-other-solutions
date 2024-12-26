// TC and SC -> O(n)

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1); // New list to store answer
        ListNode* tail = dummyHead; // Pointer for new list
        int carry = 0; // Var to hold carry

	// Loop until either of the lists are exhausted or the carry is 0
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int dig1 = (l1 != nullptr) ? l1->val : 0; // Get the digit from l1
            int dig2 = (l2 != nullptr) ? l2->val : 0; // Get the digit from l2

            int sum = dig1+dig2+carry; // Sum the current digits and carry, if any

            int digit = sum % 10; // Get the sum's digit
            carry = sum / 10; // See if there's a carry

            ListNode* newDigit = new ListNode(digit); // Create a new node with the new digit
            tail->next = newDigit; // Chain the newly created node 
            tail = tail->next; // Move the pointer forward

            l1 = (l1 != nullptr) ? l1->next : nullptr; // Move l1 and l2 pointers forward, if they exist
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
	
	// Finally get the resultant list and delete the placeholder node
        ListNode* res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};
