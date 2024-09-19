// Reversing a DLL, Approach 1 - Using Stack (Brute Force)
// TC: O(2n); SC: O(n)

Node* reverseDLL(Node* head)
{      
    if(head == nullptr){
        return nullptr;
    }

    if(head->next == nullptr){
        return head;
    }

    Node* curr = head;
    stack<int> st;

    while(curr!=nullptr){ // Pass 1 - O(n)
        st.push(curr->data);
        curr = curr->next;
    }

    Node* newHead = new Node(st.top());
    curr = newHead;
    st.pop();

    while(!st.empty()){ // Pass 2 - O(n)
        Node* temp = new Node(st.top());
        st.pop();
        temp->prev = curr;
        curr->next = temp;
        curr = temp;
    }
    return newHead;

}

// Approach 2 - Swapping the Links
// TC: O(n); SC: O(1)

Node* reverseDLL(Node* head)
{    
    if(head == nullptr){
        return nullptr;
    }

    if(head->next == nullptr){
        return head;
    }

    Node* curr = head;
    Node* last = nullptr;

    while(curr!=nullptr){
        last = curr->prev;
        curr->prev = curr->next;
        curr->next = last;

        curr = curr->prev;
    }
    return last->prev;

}

// Approach 2 - Swapping the links alternate version

DLLNode* reverseDLL(DLLNode* head) {
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    
    DLLNode* curr = head;
    DLLNode* swap = nullptr;
    
    while(curr != nullptr){
        swap = curr->next;  // Store next instead of prev
        curr->next = curr->prev;
        curr->prev = swap;
        
        if(swap == nullptr) {
            // We've reached the end of the original list
            return curr;  // This is our new head
        }
        
        curr = swap;  // Move to the next node
    }
    
    return nullptr;
} 
