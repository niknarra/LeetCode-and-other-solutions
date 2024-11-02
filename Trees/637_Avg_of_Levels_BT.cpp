class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);
        double curr_avg;

        while(!q.empty()){
            int nodesAtCurrLevel = q.size();
            double curr_sum = 0;

            for(int i=0;i<nodesAtCurrLevel;i+=1){
                TreeNode* curr = q.front();
                q.pop();

                curr_sum+=curr->val;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            curr_avg = curr_sum/nodesAtCurrLevel;
            ans.push_back(curr_avg);
        }
        return ans;
    }
};
