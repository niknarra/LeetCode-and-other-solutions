// Approach 1
// O(n)

class Solution {
public:

    void inorder(TreeNode* root, vector<int>& values){
        if(root == nullptr) return;

        inorder(root->left, values);
        values.push_back(root->val);        
        inorder(root->right, values);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> values;

        inorder(root, values);

        return values[k-1];
        
    }
};

// Approach 2
// O(h)
// We introduce an early stoppage condition

class Solution {
public:
    int inorder(TreeNode* root, int& count, int k) {
        if (root == nullptr)
            return -1; // Return -1 or any invalid value if node is null

        // Traverse the left subtree
        int left = inorder(root->left, count, k);
        if (left != -1)
            return left; // If we found the result in the left subtree, return it

        // Increment the count when visiting the current node
        count++;
        if (count == k)
            return root->val; // If count equals k, return the current node's value

        // Traverse the right subtree
        return inorder(root->right, count, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;

        return inorder(root, count, k);
    }
};
