class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        
        if(root==nullptr) return ans;
        
        queue<pair<Node*, int>> q; // Queue to load the pair that holds a node and it's level
        map<int, int> mpp; // Map to check if a node for the level is already loaded 
        
        q.push({root, 0}); // Initially push the root node with level 0
        
        while(!q.empty()){ 
            
            auto curr = q.front();
            q.pop();
            
            Node* curr_node = curr.first;
            int curr_level = curr.second;
            
	    // If the current node is not in the map, push it to the map
            if(mpp.find(curr_level) == mpp.end()) mpp[curr_level] = curr_node->data;
            
	    // Else, update with the last seen node at that level
	    else mpp[curr_level] = curr_node->data;
            
            if(curr_node->left) q.push({curr_node->left, curr_level-1});
            if(curr_node->right) q.push({curr_node->right, curr_level+1});
            
        }

	// Load the answer vector with the nodes in the map        

        for(auto it:mpp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
