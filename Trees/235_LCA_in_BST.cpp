// Optimal Approach
// TC: O(h); SC: O(1)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return root;

        int curr = root->val;

        if(curr < p->val && curr < q->val){ // If current node is smaller than both p and q, as it is a BST, we go to the right
            return lowestCommonAncestor(root->right, p, q);
        }

        if(curr > p->val && curr > q->val){ // If larger, we go to the left
            return lowestCommonAncestor(root->left, p, q);
        }

        return root; // In case one is smaller and one is bigger, the current node will be the LCA as the path of p and q is splitting
    }
};
