#include <bits/stdc++.h> 
/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int val) {
            this->data = val;
            next = NULL;
            prev = NULL;
        }
        ~Node() {
            if(next != NULL || prev != NULL){
                delete next;
            }
        }
};

************************************************************/

Node* insert(int k, int val, Node *head) {
    // Write Your Code Here.
    if(head == nullptr){
        if(k == 0){
            Node* newHead = new Node(val);
            return newHead;
        }
        return nullptr;
    }

    if(k==0){
        Node* newHead = new Node(val);
        newHead->next = head;
        head->prev = newHead;
        return newHead;
    }

    int curr_index = 0;
    Node* curr = head;
    Node* last = nullptr;

    while(curr != nullptr){
        if(curr_index == k){
            Node* temp = new Node(val);
            temp->next = curr;
            temp->prev = curr->prev;
            curr->prev->next = temp;
            curr->prev = temp;

            return head;
        }
        else{
            curr_index += 1;
            last = curr;
            curr = curr->next;
        }
    }

    if(curr_index == k){
        Node* temp = new Node(val);
        last->next = temp;
        temp->prev = last;
    }


    return head;
}


