// The maximum value in a BST will always be the right most node

// Recursive Approach

int maxValue(Node* root){

	if(root->right == nullptr){
		return root->val;
	}

	return maxValue(root->right);
}

// Iterative Approach

int maxValue(Node* root){

	while(root->right != nullptr){

		root = root->right;

	}

	return root;
}

// TC will be O(n) in both approaches
