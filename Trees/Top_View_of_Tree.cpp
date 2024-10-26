class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        
        if(root==nullptr) return ans;
        
        queue<pair<Node*, int>> q; // Queue to load the current node and it's level
        map<int, int> mpp; // Map to hold the unique nodes at each level
        
        q.push({root, 0}); // Initially push the root with a level of 0
        
        while(!q.empty()){
            
            auto curr = q.front();
            q.pop();
            
            Node* node = curr.first;
            int level = curr.second;
            
   	    // If the current node is not in the map, push it with its current value
            if (mpp.find(level) == mpp.end()) mpp[level] = node->data;
            
	    // Else, just ignore as we only see the first node at each level when looking from the top    

            if (node->left) q.push({node->left, level-1});
            
            if (node->right) q.push({node->right, level+1});
            
        }
        
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        
        return ans;
    }

};
