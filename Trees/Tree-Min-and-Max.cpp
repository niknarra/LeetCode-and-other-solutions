-------- To Find Min ---------

// Iterative Approach

int treeMin(Node* root){
    
    if(root == nullptr){
        return -1;
    }
    
    deque<Node*> q;
    q.push_front(root);
    int ans = INT_MAX;
    
    while(!q.empty()){
        
        Node* curr = q.front();
        q.pop_front();
        
        if(curr->value < ans){
            ans = curr->value;
        }
        
        if(curr->left) q.push_back(curr->left);
        
        if(curr->right) q.push_back(curr->right);
        
    }
    
    return ans;
    
}

// Recursive Approach

int treeMinRecursive(Node* root){
    if(root == nullptr){
        return INT_MAX;
    }
    
    int leftMin = treeMinRecursive(root->left);
    int rightMin = treeMinRecursive(root->right);
    
    return min(root->value,leftMin,rightMin);
       
}

// Both approaches - O(n)

-------- To Find Max ---------

// Iterative Approach


