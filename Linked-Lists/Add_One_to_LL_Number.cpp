class Solution {
public:
    // Function to reverse a linked list
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr) {
            Node* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev; // Return the new head of the reversed list
    }

    // Function to add one to the number represented by the linked list
    Node* addOne(Node* head) {
        // Edge case: if the list is empty, return nullptr
        if (head == nullptr) {
            return nullptr;
        }

        // Reverse the linked list to make it easier to add one from the least significant digit
        Node* reversedHead = reverse(head);
        Node* curr = reversedHead;
        
        int carry = 1; // We start with a carry of 1, since we're adding 1 to the number

        // Traverse the reversed list and add the carry
        while (curr != nullptr) {
            curr->data += carry;

            if (curr->data == 10) {
                curr->data = 0; // If there's a carry-over, set current node to 0
                carry = 1;      // Continue carrying over to the next digit
            } else {
                carry = 0;      // No carry-over, so we can break out
                break;
            }

            // Move to the next node
            if (curr->next == nullptr && carry == 1) {
                // If we're at the last node and still have a carry, create a new node
                curr->next = new Node(1);
                carry = 0;
            }

            curr = curr->next;
        }

        // Reverse the list back to its original order
        Node* resultHead = reverse(reversedHead);
        return resultHead; // Return the new head of the list
    }
};
