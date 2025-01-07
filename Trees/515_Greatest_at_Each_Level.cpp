// Approach - DFS and get the largest value from each level
// TC: O(n) and SC: O(w) or O(h) in worst case

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;

        if(root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int currNodes = q.size();
            int currMax = INT_MIN;
            for(int i = 0;i<currNodes;i+=1){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->val > currMax){
                    currMax = curr->val;
                }

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(currMax);
        }
    return ans;
    }
};
