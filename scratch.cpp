#include <iostream>
using namespace std;

class Node{
public:
	int value;
	Node* next;
	Node* prev;

	public:

	Node(int newValue){
		value = newValue;
		next = nullptr;
		prev = nullptr;
	}

	Node(int newValue, Node* newNext, Node* newPrev){
		value = newValue;
		next = newNext;
		prev = newPrev;
	}
};

Node* reverse(Node* head){

    Node* curr = head;
    Node* back = nullptr;

    while(curr!=nullptr){
        Node* front = curr->next;
        curr->next = curr->prev;
        curr->prev = front;

        back = curr;

        curr = front;
    }
    return back;
}

int main(){
    cout<<"Doubly Linked Lists Hands-On"<<endl;

    Node* head = new Node(7);
    Node* temp = new Node(8);
    head->next = temp;
    temp->prev = head;

    Node* ans = reverse(head);

    cout<<ans->value;

    return 0;
}
