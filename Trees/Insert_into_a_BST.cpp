// Leetcode 701

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            TreeNode* newRoot = new TreeNode(val);
            return newRoot; 
        }

        if(val > root->val){
            root->right = insertIntoBST(root->right, val);
        }else{
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};
