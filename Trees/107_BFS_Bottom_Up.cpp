//General BFS but store each level nodes at the start index using the insert function

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int nodesAtCurrLevel = q.size();
            vector<int> curr_nodes;
            for(int i=0;i<nodesAtCurrLevel;i+=1){
                
                TreeNode* curr = q.front();
                q.pop();

                curr_nodes.push_back(curr->val);

                if(curr->left) q.push(curr->left);

                if(curr->right) q.push(curr->right);
            }
            ans.insert(ans.begin(), curr_nodes);
        }
        return ans;
    }
};

// Or, simply reverse the resultant vector

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int nodesAtCurrLevel = q.size();
            vector<int> curr_nodes;
            for(int i=0;i<nodesAtCurrLevel;i+=1){
                
                TreeNode* curr = q.front();
                q.pop();

                curr_nodes.push_back(curr->val);

                if(curr->left) q.push(curr->left);

                if(curr->right) q.push(curr->right);
            }
            ans.push_back(curr_nodes);
        }
	reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Either way, TC and SC will both be O(n)
