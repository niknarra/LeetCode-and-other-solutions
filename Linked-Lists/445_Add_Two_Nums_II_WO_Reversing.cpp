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
        stack<int> st1;
        stack<int> st2;

        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        while (curr1 != nullptr) {
            st1.push(curr1->val);
            curr1 = curr1->next;
        }

        while (curr2 != nullptr) {
            st2.push(curr2->val);
            curr2 = curr2->next;
        }

        ListNode* ans = nullptr;
        int carry = 0;

        while (!st1.empty() || !st2.empty() || carry != 0) {
            int digit1 = 0;
            if (!st1.empty()) {
                digit1 = st1.top();
                st1.pop();
            }

            int digit2 = 0;
            if (!st2.empty()) {
                digit2 = st2.top();
                st2.pop();
            }

            int currSum = digit1 + digit2 + carry;
            int digit = currSum % 10;
            carry = currSum / 10;

            ListNode* newDigit = new ListNode(digit);
            newDigit->next = ans;
            ans = newDigit;
        }
        return ans;
    }
};
