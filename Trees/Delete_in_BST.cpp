class Solution {
public:

    TreeNode* deleteKey(TreeNode* root){ // Helper function that actually implements the deletion logic
        if(root->left == nullptr) return root->right; // If leftchild is null, simply return the right as there is nothing we can do

        else if(root->right == nullptr) return root->left; // Similarly for rightchild

	// In case both childs exist, we have to tag the right child to the right most child of the leftchild

        TreeNode* rightChild = root->right; // Store the current right child -> the child to be tagged
        TreeNode* lastRight = rightMost(root->left); // Get the right most child of leftchild
        lastRight->right = rightChild; // Map rightmost leftchild's right to rightchild
        
        return root->left; // Return root's left which will now have the updated subtree
    }

    TreeNode* rightMost(TreeNode* root){ // Function to get rightmost value
        if(root->right == nullptr) return root; 

        return rightMost(root->right); // Recur as long as we reach leaf node
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;

        if(root->val == key){ // If root itself has to be deleted
            return deleteKey(root); // Call the function with root
        }

        TreeNode* curr = root; // Store the root incase we don't perform a deletion

        while(root != nullptr){
		// Find the key by traversing through the tree
            if(root->val > key){
                if(root->left && root->left->val == key){
                    root->left = deleteKey(root->left);
                    break;
                }else{
                    root = root->left;
                }
            }else{
                if(root->right && root->right->val == key){
                    root->right = deleteKey(root->right);
                    break;
                }else{
                    root = root->right;
                }
            }
        }
        return curr;
    }
};
