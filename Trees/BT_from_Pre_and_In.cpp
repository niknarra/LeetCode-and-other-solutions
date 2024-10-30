// Leetcode 105
//Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

// The root will always be the first element in the preorder vector

// Now that we know the root, from the inorder vector, everything on its left will be the left subtree and everything on the right will be right subtree

// Within this sub list, we can refer to the preorder list again to get the root, left and right

// This becomes a recursive process

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if(preorder.size() == 1 && inorder.size() == 1) return new TreeNode(preorder[0]); // If there is only element, it will be the root 
        
        TreeNode* root = new TreeNode(preorder[0]); // The root will always be the first element in the preorder (Root->Left->Right)
	
	
	
        return root;
}
