// Optimal Approach
// TC: O(n); SC:O(1)

class Solution {
public:

    bool isValidBST(TreeNode* root){
        return isValidBST(root, LONG_MIN, LONG_MAX); // Let the root value be in bw long min and max
    }

    bool isValidBST(TreeNode* root, long min_val, long max_val) { // Helper function
        if(root == nullptr) return true;

        if(root->val >= max_val || root->val <= min_val) return false; // If a root has a value more than the limits, return false

        return isValidBST(root->left, min_val, root->val) && isValidBST(root->right, root->val, max_val); // Recur left & right

    }
};
