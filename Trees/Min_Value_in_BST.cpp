Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Intuition: Find the left most node and return it or it's value

// Recursive Approach

class Solution {
  public:
    int minValue(Node* root) {
        
        if(root->left == nullptr){
            return root->data;
        }
        
        return minValue(root->left);
    }
};

// Iterative Approach

class Solution {
  public:
    int minValue(Node* root) {
        
	while(root->left != nullptr){
            root = root->left;
        }
        
	return root->data;
    }
};
