// Linked List Def

#include <bits/stdc++.h>
using namespace std;

class Node{ // Can also use Struct but class goes well with OOP Paradigm

  public: // In a class members are private by default as opposed to Struct
    
    int data; // This hold the data in our example let's say the numbers

    Node* next; // This is a Node object pointer that points to the next node in the list
    
    Node(int newData, Node* nextNode){ // The class constructor to create new Nodes/Node objects

        data = newData; // Initializing the newData passed to build the new Node Object

        next = nextNode; // Setting the next node pointer

    }
    
    Node(int newData){ // The class constructor to set the next node to be nullptr by default
        data = newData;
        next = nullptr;
    }
};

// Function to Convert an Array into a LL

Node* convertArr2LL(int arr[], int n) {
    if (n == 0) {

        return nullptr; // If the array is empty, return nullptr

    }

    Node* head = new Node(arr[0]); // Initializing the head to be the first element

    Node* curr = head; // Initializing the iterator variable curr to be at head initially
    
    for (int i = 1; i < n; i += 1) { // Loop through elements starting at 1, as 0 element is head

        Node* temp = new Node(arr[i]); // Constructing a new Node object with arr[i]th element

        curr->next = temp; // Linking the current node to the new node

        curr = temp; // Moving curr to temp, which is the arr[i]th element
    }
    return head; // Returning the head, which is chained with the rest of the elements
}

// Function to Print all the Nodes of a LL

void displayNodes(Node* head){
    
    Node* curr = head; // Setting the current variable to be at head initially
    
    if (curr == nullptr) { // Check if the list is empty
        cout << "List is empty" << endl;
        return;
    }
    
    while(curr){ // While curr is not false or not equal to nullptr

        cout<<curr->data; // Printing the data

        if (curr->next) {
            cout << " -> "; // Print arrow only if there is a next node
        }
        
        curr = curr->next; // Moving curr to the next Node in the LL
    }
    cout << " -> null" << endl; // Indicate the end of the LL
}

// Function to Get the Length of a LL

int lengthOfLL(Node* head){
    int length = 0; // Declaring the length variable which will hold our answer and initializing it to 0
 
   Node* curr = head; // Setting the current node to be the head
    
    while(curr){ // While curr is not nullptr

        length += 1; // We increment the length by 1

        curr = curr->next; // Move the curr to the next Node

    }
    
    return length; // Return the final length
}

// Function to check if a given Key is present in a LL

bool checkKey(Node* head, int key){
    Node* curr = head; // Setting the current node to be the head
    
    while(curr){ // While curr is not nullptr

        if(curr->data == key){ // If the curr node holds the key value

            return true; // We found the key and will return True
        }

        curr = curr->next; // If not, move the curr to the next Node
    }
    
    return false; // Return false as the key is not present
}

// Function to return the node that contains the key

Node* returnKeyNode(Node* head, int key){
    Node* curr = head; // Setting the current node to be the head
    
    while(curr){ // While curr is not nullptr
 
       if(curr->data == key){ // If the curr node holds the key value

            return curr; // We found the node and will return it
        }

        curr = curr->next; // If not, move the curr to the next Node
    }
    
    return nullptr; // By default return nullptr if key is not found in any node
}

// Function to ADD a node at the end of a LL

Node* addElementAtTheEnd(Node* head, int newNode){

    Node* curr = head; // Setting the current node to be the head
    
    if(curr == NULL){ // Checking if the list is empty

        head = new Node(newNode); // We set the head to be the new node with the new element

        return head; // Return the head and exit

    }
    
    while(curr->next != NULL){ // While loop to get to the last element of the LL
 
       curr = curr->next; // Move curr to the next element as long as the next is not null

    }
    
    curr->next = new Node(newNode); // Create a new node and chain it to the last element of the LL
    
    return head; // Return head and exit
    
}

// Function to DELETE the TAIL node 

Node* delElementAtTheEnd(Node* head){

    Node* curr = head; // Setting the current node to be the head

    Node* prev = nullptr; // Setting a variable previous
    
    if(curr == NULL){ // Checking if the list is empty

        return nullptr; // Return nullptr and exit

    }
    
    if(curr->next == NULL){ // Checking if list has a single element

        delete head; // Then we will directly delete the head

        return nullptr; // And return a nullptr as LL is empty

    }
    
    while(curr->next != NULL){ // While loop to get to the last element of the LL

        prev = curr; // Set prev to the current node

        curr = curr->next; // Move curr to the next element

    }
    
    prev->next = nullptr; // Break the chain and set the last but one element to be the tail
    
    delete curr; // Free up the memory
    
    return head; // Return head and exit
    
}

// Function to DELETE the HEAD

Node* delHead(Node* head){
    
    if(curr == NULL){ // Checking if the list is empty

        return nullptr; // Return nullptr and exit

    }
    
    if(curr->next == NULL){ // Checking if list has a single element

        delete head; // Then we will directly delete the head

        return nullptr; // And return a nullptr as LL is empty
 
   }
    
    Node* newHead = head->next; // Setting the second element to be the new head
    
    delete head; // Free up the memory
    
    return newHead; // Return new head and exit
}

// Function to DELETE a node at a GIVEN POSITION

Node* delElementAtPos(Node* head, int pos){
    
    Node* curr = head; // Setting the current node to be the head
    Node* prev = nullptr;
    int curr_index = 0;
    
    if(curr == nullptr){ // Checking if the list is empty

        return nullptr; // Return nullptr and exit

    }
    
    if(pos == 0){ // If the position is 0 which is head, we need to move head by 1

        Node* temp = head; // Set a temp variable to be head

        head = head -> next; // Move head to the next element

        delete temp; // Delete and free the memory of old head

        return head; // Return the head and exit

    }
    
    while(curr->next!=nullptr){ // While the current is not nullptr 

        if(pos == curr_index){ // Check is current index is the position asked to remove from

            prev->next = curr->next; // Then chain the previous and the next nodes

            delete curr; // Delete the current Node and free memory

            return head; // Return the head and exit

        }

        curr_index += 1; // If not, increment the current index by 1

        prev = curr; // Set prev to current element

        curr = curr->next; // Move current to the next element

    }
 
   return head; // Return head if pos is not in range of length of list
}

// Function to DELETE a VALUE from a LL

Node* deleteGivenValue(Node* head, int value){
    
    if(head == nullptr){ // Check if the list is empty

        return nullptr; // Then return a nullptr

    }
    
    if(head->data == value){ // Check if head has the given value

        Node* temp = head; // Then set the head to a temp node

        head = head->next; // Move head to the next node

        delete temp; // Delete and free the memory

        return head; // Return the new head and exit

    }
    
    Node* curr = head; // Setting the current node to be the head

    Node* prev = nullptr; // Setting the previous node to be a nullptr initially
    
    while(curr != nullptr){ // While the current is not nullptr 

        if(curr->data == value){ // Check if current node has the value asked to remove 

            prev->next = curr->next; // Then chain the previous and the next nodes

            delete curr; // Delete the current Node and free memory

            return head; // Return the head and exit

        }
        prev = curr; // Set prev to current element

        curr = curr->next; // Move current to the next element

    }
 
   return head; // Return head if value is not in list
}

// Function to ADD at HEAD

Node* addAtHead(Node* head, int value){
    
    Node* newHead = new Node(value); // Create a new node with the given value
    
    newHead->next = head; // Chaining the new head with the rest of the list
    
    return newHead; // Returning new head
    
}

// Function to ADD at TAIL

Node* addAtTail(Node* head, int value){
    if(head == nullptr){ // If the list is empty

        Node* newHead = new Node(value); // Create a new node with the given value

        return newHead; // Return new head which will also be the tail and exit

    }
    
    Node* curr = head; // Setting the current node to be the head

    while(curr->next != nullptr){ // While current is not null

        curr = curr->next; // Traverse to the last node
 
   }
    
    curr->next = new Node(value); // Set the last node's next to be the new node
    
    return head; // Returning new head
}

// Function to ADD at a GIVEN POSITION

Node* addAtPos(Node* head, int pos, int value){
    if (head == nullptr) { // If the list is empty

        if (pos == 1) { // Handle adding at position 1 when the list is empty

            return new Node(value); // Create the first node
        }

        return nullptr; // If pos is greater than 1 and the list is empty, return nullptr
    }
    
    if(pos == 1){ // If pos is 1, we need to add a new head

        Node* newHead = new Node(value,head); // create a new node to point to head

        return newHead; // return the new head
    }
    
    Node* curr = head; // Setting the current node to be the head

    Node* prev = nullptr; // Setting the previous node to be a nullptr initially

    int curr_index = 1; // Set current index to be at 1
    
    while(curr != nullptr){ // While curr is not null

        if(curr_index == pos){ // If current index is equal to given position

            prev->next = new Node(value, curr);  // Link prev to the new node, and new node to curr

            return head; // Return head and exit
        }

        curr_index += 1; // Increment current index

        prev = curr; // Set Prev to current

        curr = curr->next; // Move Curr to the next node
    }
    
    return head; // Return the unchanged head if the position is beyond the list length
}

// Function to ADD at a given VALUE

Node* addValueAtTarget(Node* head, int value, int target){
    if (head == nullptr) { // If the list is empty, the target won't be present

        return nullptr; // return nullptr and exit
    }
    
    if(head->data == target){ // If head's data is equal to target, we need to add a new head

        Node* newHead = new Node(value,head); // create a new node to point to head

        return newHead; // return the new head
    }
    
    Node* curr = head; // Setting the current node to be the head

    Node* prev = nullptr; // Setting the previous node to be a nullptr initially

    while(curr != nullptr){ // While curr is not null

        if(curr->data == target){ // If current node value is equal to given target

            prev->next = new Node(value, curr);  // Link prev to the new node, and new node to curr

            return head; // Return head and exit
        }
        prev = curr; // Set Prev to current

        curr = curr->next; // Move Curr to the next node
 
   }
    
    return head; // Return the unchanged head if the target doesn't exist in the list
}

//
