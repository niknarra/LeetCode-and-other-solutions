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

--------- Deletions ---------

// Function to DELETE the HEAD of DLL

Node* deleteHeadOfDLL(Node* head){
  if(head == nullptr){ // Check if the list is empty

    return nullptr; // Return nullptr and exit
  }
  
  Node* temp = head; // Separate the head from the rest of the list

  head = head->next; // Move the head to the next node

  if(head != nullptr){ // Check if the list is not empty
 
   head->prev = nullptr; // Set the previous node of the head to nullptr
  }
  
  delete temp; // Free the memory of the old head
  
  return head; // Return the new head
}

// Function to DELETE the TAIL of DLL

Node* deleteTailOfDLL(Node* head){
  if(head == nullptr){ // Check if the list is empty

    return nullptr; // Return nullptr and exit
  }

  Node* curr = head; // Create a node curr which is initially equal to head

  while(curr->next != nullptr){ // Iterate until the next node is nullptr

    curr = curr->next; // Move curr to the next node
  }

  if(head == curr){ // Check if the list has only one node

    delete head; // Free the memory of the head

    return nullptr; // Return nullptr and exit
  }

  curr->prev->next = nullptr; // Set the next node of the previous node to nullptr
 
 delete curr; // Free the memory of the tail

  return head; // Return the head
}

// Function to DELETE at a GIVEN POS

Node* deleteAtPos(Node* head, int pos){ 
  if(head == nullptr){ // Check if the list is empty
  
  return nullptr; // Return nullptr and exit
  }

  if(pos == 1){ // Check if the position is 1

    Node* temp = head; // Separate the head from the rest of the list
  
  head = head->next; // Move the head to the next node

    if (head != nullptr) { // Check if the list is not empty

    head->prev = nullptr; // Set the previous node of the head to nullptr
    }

    delete temp; // Free the memory of the old head

    return head; // Return the new head

  }

  int curr_index = 1; // Create a variable curr_index which is initially equal to 1

  Node* curr = head; // Create a node curr which is initially equal to head

  while(curr->next != nullptr){ // Iterate until the next node is nullptr

    if(curr_index == pos){ // Check if the current index is equal to the position

      if(curr->next != nullptr){ // Check if the next node is not nullptr

      curr->prev->next = curr->next; // Set the next node of the previous node to the next node

      curr->next->prev = curr->prev; // Set the previous node of the next node to the previous node

      }
    }else{

      curr->prev->next = nullptr; // Set the next node of the previous node to nullptr
    }
      delete curr; // Free the memory of the current node

      return head; // Return the head
  }
    }
    curr_index += 1; // Increment the current index

    curr = curr->next; // Move curr to the next node
  }
  return head; // Return the head
}

// Function to DELETE a GIVEN VALUE

Node* deleteAtGivenValue(Node* head, int value){ 
  if(head == nullptr){ // Check if the list is empty

    return nullptr; // Return nullptr and exit
  }

  if(head->data == value){ // Check if the head's data is equal to the value

    Node* temp = head; // Separate the head from the rest of the list

    head = head->next; // Move the head to the next node

    if(head!=nullptr){ // Check if the list is not empty

      head->prev = nullptr; // Set the previous node of the head to nullptr
    }
    delete temp; // Free the memory of the old head

    return head; // Return the new head
  }

  Node* curr = head; // Create a node curr which is initially equal to head
  
  while(curr != nullptr){ // Iterate until the current node is nullptr

    if(curr->data == value){ // Check if the current node's data is equal to the value

      if(curr->next != nullptr){ // Check if the next node is not nullptr

        curr->prev->next = curr->next; // Set the next node of the previous node to the next node

        curr->next->prev = curr->prev; // Set the previous node of the next node to the previous node
      }
      }else{

        curr->prev->next = nullptr; // Set the next node of the previous node to nullptr
      }
      delete curr; // Free the memory of the current node

      return head; // Return the head
    }

    curr = curr->next; // Move curr to the next node
  }
 
 return head; // Return the head
}

--------- Insertions ---------

// Function to INSERT a NEW HEAD

Node* insertAtHead(Node* head, int value){
  if(head == nullptr){ // Check if the list is empty

    Node* newHead = new Node(value); // Create a new node with the value

    return newHead; // Return the new head and exit
  }

  Node* temp = new Node(value); // Create a new node with the value

  temp->next = head; // Set the next node of the new node to the head

  temp->prev = nullptr; // Set the previous node of the new node to nullptr
 
  head->prev = temp; // Set the previous node of the head to the new node and chain

  return temp; // Return the new head
} 

// Function to INSERT AFTER HEAD

Node* insertAfterHead(Node* head, int value){

  if(head == nullptr){ // Chec if the list is empty

    Node* newHead = new Node(value); // Create a new head with the value

    retrun newHead; // Rerturn the new head and exit
  }
  
  Node* temp = new Node(value); // Create a new node with the value

  temp->prev = head; // Set the previous node of the new node to the head

  temp->next = head->next; // Set the next node of the new node to the next node of the head

  if (head->next != nullptr) { // Chack if the next node of the head is not nullptr
 
     head->next->prev = temp; // If not, set the previous node of the next node of the head to the new node
  }

  head->next = temp; // Set the next node of the head to the new node and chain

  return head; // Return the head
}

// Function to INSERT at GIVEN POS


