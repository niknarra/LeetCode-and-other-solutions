// Optimal Approach

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    
    if (root->data == input){
        return root->data;
    }
    
    if (root->data > input) {
        int leftCeil = findCeil(root->left, input);
        
        return (leftCeil != -1) ? leftCeil : root->data;
    }
    
    return findCeil(root->right, input);
}

