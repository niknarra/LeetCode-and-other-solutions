// Leetcode 101

class Solution {
public:
   // Helper function to check if the current nodes are mirrors of each other or not
    bool isMirror(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr) return true; // If both are null, they are same and nothing to compare further

        if(left == nullptr || right == nullptr) return false; // If one of them is null, they are not same

        return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
    	// Ultimately we check if the values are same and if the left sub tree is a mirror and if the right subtree is a mirror
    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true; // If root is null, the tree is empty and empty tree->symmetrical

        return isMirror(root->left, root->right); // Call the helper function

    }
};
