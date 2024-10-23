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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == nullptr) return ans;

        deque<TreeNode*> q;
        q.push_front(root);

        while(!q.empty()){
            
            int nodesAtCurrLevel = q.size();
            vector<int> curr_nodes = {};

            for(int i=0;i<nodesAtCurrLevel;i+=1){
                TreeNode* curr = q.front();
                curr_nodes.push_back(curr->val);
                q.pop_front();

                if(curr->left) q.push_back(curr->left);

                if(curr->right) q.push_back(curr->right);
            }

            ans.push_back(curr_nodes);
        }

        return ans;
    }
};
