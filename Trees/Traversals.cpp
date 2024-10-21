// DFS Traversals

// Pre Order Traversal - Root, Left, Right

void preOrder(Node* root){

	if(root == nullptr){ // If passed node is null, we passed a leaf node
		
		return; // So we return

	}

	cout<<root->val<<endl; // If passed node is not null, it must be the root, so we print it

	preOrder(root->left); // Now we will recrusively go through left sub tree

	preOrder(root->right); // Now we will recursively go through right sub tree

}

// Post Order Traversal - Left, Right, Root

void postOrder(Node* root){

	if(root == nullptr){ // If passed node is null,
	
		return;	// We will return without any action

	}
	
	postOrder(root->left); // If not, then recrusively traverse the left sub tree

	postOrder(root->right); // Then the right sub tree

	cout<<root->val<<endl; // We will be left with the root of the sub tree, so print it
}

// In Order Traversal - Left, Root, Right

void inOrder(Node* root){

	if(root == nullptr){ // If current node is null,
		
		return; // Simply return
		
	}

	inOrder(root->left); // Recursively traverse the left sub tree

	cout<<root->val<<endl; // We will now be at the root of the sub tree, so print it

	inOrder(root->right); // Now recursively traverse the right sub tree

}

// --------------------------------------------------------

// BFS
// Level Traversal

void levelTraversal(Node* root){

	if(root==nullptr){
		cout<<"Tree is empty";
		return;
	}

	
	dequeue<Node*> q;
	q.push_back(root);

	while(!q.empty()){
	
		Node* curr = q.front();
		q.pop_front();
		cout<<curr->val<<" ";
	
		if(curr->left){
		
			q.push_back(curr->left);			

		}	
		
		if(curr->right){

			q.push_back(curr->right);			

		}
		
	}

}

