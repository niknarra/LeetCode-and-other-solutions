// Initial approach

class Solution{

public:
    int floor(Node* root, int x) {
        
        if (root == NULL) return -1;
        
        if(root->data == x) return root->data;
        
        if(root->data < x){
            int ans = root->data;
            int rightMax = floor(root->right, x);
            return max(ans, rightMax);
        }
        else{
            return floor(root->left, x);
        }
    }
};

// Cleaned up approach

class Solution{

public:
    int floor(Node* root, int x) {
        // Code here
        if (root == NULL) return -1;
        
        if(root->data == x) return root->data;
        
        if(root->data < x){
            int rightMax = floor(root->right, x);
            return (rightMax <= x && rightMax != -1) ? rightMax : root->data;
        }
        else{
            return floor(root->left, x);
        }
    }
};
