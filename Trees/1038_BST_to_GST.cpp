// Recursive approach with helper function
// TC: O(n) and SC: O(h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Accumulator for sum
    int runningSum = 0;

    // Helper recursive function
    void converter(TreeNode* root){
        if(root == nullptr) return;
	
	// We will do a reverse inorder traversal, right->root->left
	// If there is a right node, process it first
        if(root->right){
            converter(root->right);
        }
	
	// Process the root and its value
        runningSum += root->val; // Accumulate the sum
        root->val = runningSum; // Make the current root's value the current accumulated sum

	// If there is a left child, process it next
        if(root->left){
            converter(root->left);
        }
    }

    TreeNode* bstToGst(TreeNode* root) {
        converter(root);

        return root;
    }
};
