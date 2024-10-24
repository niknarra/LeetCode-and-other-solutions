#include<iostream>

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
 #include<deque>
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == nullptr) return ans;

        deque<TreeNode*> q;
        q.push_back(root);
        bool dir = true; // Flag to check the direction

        while(!q.empty()){
            int nodesAtCurrLevel = q.size();
            vector<int> curr_nodes;

            if(dir){ // If going left->right,
            for (int i = 0; i < nodesAtCurrLevel; ++i) {
                    TreeNode* curr = q.front(); // Get the elements from the front
                    q.pop_front();
                    curr_nodes.push_back(curr->val);
                    if (curr->left) q.push_back(curr->left); // Push left and right childs normally to the back of the queue
                    if (curr->right) q.push_back(curr->right);
                }

            }else{ // If going right->left,
                for (int i = 0; i < nodesAtCurrLevel; ++i) {
                    TreeNode* curr = q.back(); // Get the elements from the back 
                    q.pop_back();
                    curr_nodes.push_back(curr->val);
                    if (curr->right) q.push_front(curr->right); // Put the right child first
                    if (curr->left) q.push_front(curr->left); // and then the left child
                }
            }
            
            ans.push_back(curr_nodes);
            dir = !dir; // Flip the direction flag
        }
        return ans;
    }
};
