struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        if(head == nullptr || head->next == nullptr){
            return 0;
        }
        
        Node* slow = head;
        Node* fast = head;
        bool cycle = false;
        
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                cycle = true;
                break;
            }
        }
        
        if(!cycle){
            return 0;
        }else{
            fast = fast->next;
            int count = 1;
            while(fast!=slow){
                count += 1;
                fast = fast->next;
            }
            return count;
        }
    }
};
