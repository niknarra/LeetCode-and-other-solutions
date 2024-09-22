// Approach 1 - Brute Force
// Use a Stack
// TC: O(2n) => O(n)
// SC: O(n) -> Not ideal

// Approach 2 - Swapping the Links
// TC: O(n + n/2 + n/2) => O(2n) => O(n)
// Sc: O(1)

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        
        // Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) { // O(n)
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr != nullptr) { // O(n/2)
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        // Compare the two halves
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev; // prev now points to the reversed second half

        while (secondHalf != nullptr) { // O(n/2)
            if (firstHalf->val != secondHalf->val) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};
