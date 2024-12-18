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

// Recursive Approach

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr ){
            return root;
        }

        if (root->val == val) return root;

        if (root->val > val) return searchBST(root->left, val);
        
        else return searchBST(root->right, val);
    }
};

// Iterative Approach

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==nullptr || root->val == val) return root;

        while(root && root->val != val){
            if(root->val > val){
                root = root->left;
            }else{
                root = root->right;
            }
        }
        return root;
    }
};

// Both cases O(n)
