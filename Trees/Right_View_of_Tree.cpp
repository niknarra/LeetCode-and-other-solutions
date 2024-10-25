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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        
        if(root == nullptr) return ans;

        deque<TreeNode*> q;
        q.push_back(root);

        while(!q.empty()){
            int nodesAtCurrLevel = q.size();

            for(int i=0;i<nodesAtCurrLevel;i+=1){
                TreeNode* curr = q.front();
                q.pop_front();

                if(i == 0) ans.push_back(curr->val);

                if(curr->right) q.push_back(curr->right);
                if(curr->left) q.push_back(curr->left);

            }
        }
        return ans;
    }
};

// Essentially, the node that appears first in a reverse BFS (right->left) at each level is the node that will be visible from the right
