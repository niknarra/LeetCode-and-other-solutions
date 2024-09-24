class Node{
	
	int value;
	Node* next;

	public:
	
	Node(int newValue){
		value = newvalue;
		next = nullptr;
	}	
	
	Node(int newValue, Node* newNext){
		value = newValue;
		next = newNext;
	}
};

