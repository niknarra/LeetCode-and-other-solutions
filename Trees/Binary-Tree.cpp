// Defining a Binary Tree Node
// Using Struct

#include<bits/stc++.h>
using namespace std;

struct Node{

	int data;
	Node* left;
	Node* right;

	Node(int newData){
	
		data = newData;
		left = right = nullptr;
	
	}

};

// Or we can also use Class, but we need to make the members public as class members are private by default.

class Node{

public:
	int data;
	Node* left;
	Node* right;

	Node(int newData){
		data = newData;
		left = right = nullptr;
	}	
};

// Populating a Tree

void populate(Node* root){
	
	bool insert;
	int value;	
	
	cout<<"Do You want to insert to the left of "<<root->data<<endl; // Ask if we want to add something to the right
	cin>>insert; 
	if(insert){

		cout<<"Enter to value to insert to the left of "<<root->data<<endl; // Get the value
		cin>>value; 
		root->left = new Node(value); // Create a new node with the given value and set it to root->left
		populate(root->left); // Begin recursion with the newly created node

	}else{// If not,
	
		root->left = nullptr; // Simply set the left node as a nullptr	

	}
	
	cout<<"Do you want to insert to the right of "<<root->data<<endl; // Repeat the same for right sub tree
	cin>>insert;
	if(insert){
		
		cout<<"Enter the value to insert to the right of "<<root->data<<endl;
		cin>>value;
		root->right = new Node(value);
		populate(root->right);
	}else{
	
		root->right = nullptr;
		
	}
}

void main(){
	
	bool build; // A boolen to check if the user wants to build a tree or not
	int temp; // a temp integer var to build the root node

	cout<<"Do you want to build a Binary Tree?"<<endl;
	cin>>build;

	if(build){ // If the user wants to build
		cout<<"Enter the root node"<<endl; // We get the root node
		cin>>temp;

		Node* root = new Node(temp); // Build the root node with the given value
		
		populate(root); // Call the helper function to populate
		
	}	
	
	cout<<"GoodBye!"
	
	}
}


