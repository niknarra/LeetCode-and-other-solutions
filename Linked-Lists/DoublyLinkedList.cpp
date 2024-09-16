// Doubly Linked List Def

class Node{
	public:
	int data;
	Node* next;
	Node* prev;

	Node(int newData, Node* newNext, Node* newPrev){
		data = newData;
		next = newNext;
		prev = newPrev;
	}
	
	Node(int newData){
		data = newData;
		next = nullptr;
		prev = nullptr;
	
	}

}

