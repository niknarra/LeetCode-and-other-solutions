// Recursive Approach

int treeSum(Node* root){
    
    if(root==nullptr){
        return 0;
    }
    
    return root->value + treeSum(root->left) + treeSum(root->right);
    
}

// Iterative Approach

int treeSumIterative(Node* root){
    
    if(root==nullptr){
        return 0;
    }
    
    deque<Node*> q;
    q.push_front(root);
    int ans = 0;
    
    while(!q.empty()){
        Node* curr = q.front();
        q.pop_front();
        ans += curr->value;
        
        if(curr->left){
            q.push_back(curr->left);
        }
        
        if(curr->right){
            q.push_back(curr->right);
        }
        
    }
    return ans;
}

// Both are O(n) but recursive approach is cleaner. But, in case there is a limit to the number of recursive calls in the call stack, we can use iterative appraoch.
