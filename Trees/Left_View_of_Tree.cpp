#include<deque>
class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int> ans;
        
        if (root==nullptr) return ans;
        
        deque<Node*> q;
        q.push_back(root);
        
        while(!q.empty()){
            int nodesAtCurrLevel = q.size();
            
            for(int i=0;i<nodesAtCurrLevel;i+=1){
                Node* curr = q.front();
                q.pop_front();
                
                if(i==0) ans.push_back(curr->data);
                
                if(curr->left) q.push_back(curr->left);
                if(curr->right) q.push_back(curr->right);
            }
        }
        return ans;
    }
};

// Essentially the first element at each level in BFS will be the node that will be visible from the left
