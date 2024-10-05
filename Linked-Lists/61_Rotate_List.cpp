// Single Shot Solution

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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==nullptr || head->next == nullptr){ // Handling edge cases
            return head;
        }

        int len=0;
        ListNode* curr = head; // Create a pointer node and set it to head initially
        ListNode* tail = nullptr; // Create a pointer to store the tail, initially set it to a nullptr

        while(curr!=nullptr){ // Traversing the list for 2 things
            tail = curr; // Finding the tail
            curr = curr->next; // And finding the length of the list
            len += 1;
        }

        int total_rotations = k%len; // Essentially, the total number of rotations will be k%len even if k>len
        int curr_rotations = 0; // To count the current rotation count

        while(curr_rotations<total_rotations){
            curr = head;
            ListNode* temp = tail; // Store the tail to attach it to head later

            while(curr->next != temp){ // Traverse to get to the last but one node
                curr = curr->next;
            } 
            curr->next = nullptr; // Now curr will be at the new tail, set it to a nullptr
            temp->next = head; // The old tail will be the new head
            head = temp; // Now new head node will be the tail we stored earlier
            tail = curr; // Update the tail
            curr_rotations += 1; // Increment the count of rotations
        }

        return head; // Return head and exit!
    }
};

