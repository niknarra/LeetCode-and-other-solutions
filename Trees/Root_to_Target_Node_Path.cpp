void rootToTargetPath(Node* root, vector<vector<int>>& ans, vector<int>& curr_path, int target){
    if(root == nullptr) return;
    
    curr_path.push_back(root->value);
    
    if(root->value == target){
        ans.push_back(curr_path);
        curr_path.pop_back();
        return;
    }
    
    rootToTargetPath(root->left, ans, curr_path, target);
    rootToTargetPath(root->right, ans, curr_path, target);
    
    curr_path.pop_back();
}

// Here, we use backtracking to make sure we discard the unnecessary nodes from the path
// and also to make sure we explore any other paths to the target node
