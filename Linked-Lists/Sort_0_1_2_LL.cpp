// Brute Force Approach
// TC: O(2n) => O(n) - 2 pass approach

class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    
    Node* segregate(Node* head) {

        // Add code here
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        
        Node* curr = head;
        
        while(curr!=nullptr){
            if(curr->data == 0){
                cnt0 += 1;
            }
            else if(curr->data == 1){
                cnt1 += 1;
            }
            else{
                cnt2 += 1;
            }
            curr = curr->next;
        }
        
        curr = head;
        
        while(curr!=nullptr){
            if(cnt0 > 0){
                curr->data = 0;
                curr = curr->next;
                cnt0 -= 1;
                continue;
            }
            if(cnt1 > 0){
                curr->data = 1;
                curr = curr->next;
                cnt1 -= 1;
                continue;
            }
            if(cnt2 > 0){
                curr->data = 2;
                curr = curr->next;
                cnt2 -= 1;
                continue;
            }
        }
        return head;
    }
};

// Approach 2 - Linking 0s, 1s and 2s
// TC: O(n) - One pass approach

class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        if(head->next == nullptr || head == nullptr){
            return head;
        }
        
        Node* list0 = new Node(-1);
        Node* temp0 = list0;
        Node* list1 = new Node(-1);
        Node* temp1 = list1;
        Node* list2 = new Node(-1);
        Node* temp2 = list2;
        
        Node* curr = head;
        
        while(curr != nullptr){
            if(curr->data == 2){
                temp2->next = curr;
                temp2 = temp2->next;
            }else if(curr->data == 1){
                temp1->next = curr;
                temp1 = temp1->next;
            }
            else{
                temp0->next = curr;
                temp0 = temp0->next;
            }
            curr = curr->next;
        }
        
        temp0->next = (list1->next != nullptr) ? list1->next : list2->next;
        temp1->next = list2->next;
        temp2->next = nullptr;
	
	delete list0;
	delete list1;
	delete list2;
	        
        return list0->next;
    }
};

