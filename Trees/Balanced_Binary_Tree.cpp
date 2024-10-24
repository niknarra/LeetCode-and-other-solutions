// Leetcode 110
// Naive Approach (my first approach)

class Solution {
public:

    int depth(TreeNode* root){
        if(root == nullptr) return 0;

        return 1 + max(depth(root->left), depth(root->right));
    }

    bool isBalanced(TreeNode* root) {

        if(root == nullptr) return true;

        if(abs(depth(root->left) - depth(root->right)) >= 2){
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);        
    }
};

// I'm calculating the depth at every node and trying to figure out if the difference is less than or equal to 1. If not, we return false.
// This works and beats 100% on Leetcode but the TC in worst case is O(n)

// Improved Approach

class Solution {
public:

    int checkDepth(TreeNode* root){
        if(root == nullptr) return 0;

        int leftDepth = checkDepth(root->left);
        if(leftDepth == -1) return -1;

        int rightDepth = checkDepth(root->right);
        if(rightDepth == -1) return -1;

        if(abs(leftDepth - rightDepth) > 1) return -1;

        return 1 + max(leftDepth, rightDepth);
    }

    bool isBalanced(TreeNode* root) {

        return checkDepth(root) != -1;
    
    }
};

// Here, we're calculating the depth and also checking if it is balanced in the checkdepth function in a bottom up approach, this will lead to an early exit and thus O(n)
// If the tree is balanced, checkBalance(root) returns the height of the tree
// If the tree is unbalanced, checkBalance(root) returns -1
