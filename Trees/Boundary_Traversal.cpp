class Solution {
public:
    // Function to handle left boundary, excluding leaf nodes
    void left(Node* root, vector<int>& ans) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return;  // Stop at leaf nodes or null
        }

        ans.push_back(root->data);  // Add current node to the boundary

        if (root->left) {
            left(root->left, ans);  // Recur on left child if it exists
        } else {
            left(root->right, ans);  // If no left child, recur on right child
        }
    }

    // Function to collect all leaf nodes
    void leafs(Node* root, vector<int>& ans) {
        if (root == nullptr) return;
        
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(root->data);  // Add leaf node
        }
        
        leafs(root->left, ans);
        leafs(root->right, ans);
    }

    // Function to handle right boundary, excluding leaf nodes and root
    void right(Node* root, vector<int>& ans) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return;  // Stop at leaf nodes or null
        }

        // Recur on right child first if it exists
        if (root->right) {
            right(root->right, ans);
        } else {
            right(root->left, ans);  // If no right child, recur on left child
        }

        ans.push_back(root->data);  // Add current node after recursion to reverse the order
    }

    vector<int> boundary(Node *root) {
        vector<int> ans;

        if (root == nullptr) return ans;  // Handle null root

        if (!(root->left == nullptr && root->right == nullptr)) {
        ans.push_back(root->data);  // Add root node
        }

        // Add the left boundary excluding the root and leaf nodes
        if (root->left) left(root->left, ans);

        // Add all leaf nodes
        leafs(root, ans);

        // Add the right boundary excluding the root and leaf nodes
        if (root->right) right(root->right, ans);

        return ans;
    }
};
