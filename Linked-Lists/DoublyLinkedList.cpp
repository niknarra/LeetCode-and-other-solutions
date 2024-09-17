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

};

// Function to BUILD a DLL from an ARRAY

Node* arrayToDLL(int arr[], int n){ // n is assumed to be the length of array

  if(n==0){ // If array is empty

    return nullptr; // Return nullptr and exit
  }
  
  Node* head = new Node(arr[0]); // Create the DLL's head using the 0th element

  Node* prev = head; // Create another node prev which is initially equal to head

  for(int i=1;i<n;i+=1){ // Iterate from the 1st element to the last

    Node* temp = new Node(arr[i],nullptr,prev); // Create a new node with the ith element

    prev->next = temp; // Chain the previous node with the temp node

    prev = prev->next; // Move prev to the current node which is temp
  }

return head; // Return the head
}

