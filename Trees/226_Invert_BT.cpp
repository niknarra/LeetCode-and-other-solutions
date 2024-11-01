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
    TreeNode* invertTree(TreeNode* root) {
        if(root){
            TreeNode* left = root->left;
            TreeNode* right = root->right;

            root->left = right;
            root->right = left;

            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};

// Iterative Approach

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            swap(curr->left, curr->right);

            if(curr->left){
                q.push(curr->left);
            }

            if(curr->right){
                q.push(curr->right);
            }

        }
        return root;

    }
};
