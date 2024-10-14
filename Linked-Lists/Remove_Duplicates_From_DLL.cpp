class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        Node* curr = head;
        
        while (curr->next != nullptr) {
            if (curr->data == curr->next->data) {
                Node* temp = curr->next;
                
                while (temp != nullptr && temp->data == curr->data) {
                    temp = temp->next;
                }
                
                curr->next = temp;
                if (temp != nullptr) temp->prev = curr;
                
            } else {
                curr = curr->next;
            }
        }
        
        return head;
    }
};
