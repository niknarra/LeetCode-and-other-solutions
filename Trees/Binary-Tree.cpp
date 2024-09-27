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


