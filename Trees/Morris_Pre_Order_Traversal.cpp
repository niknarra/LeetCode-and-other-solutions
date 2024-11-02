// In this approach, we can get the preorder traversal with constant O(1) space

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        TreeNode* curr = root; // Initialize a current node with the root

        while(curr){ // As long as the curr node is valid i.e., not nullptr
            if(curr->left){ // Move to it's left
                TreeNode* prev = curr->left; // Store the previous node

                while(prev->right){ // Move to the right-most node
                    prev = prev->right;
                }

                prev->right = curr->right; // Once we get the rightmost node, map to the curr's right
                curr->right = curr->left; // Now curr's right will be left
                curr->left = nullptr; // Left will be nullptr as we're flattening it
            }
            ans.push_back(curr->val); // Push the current node to ans vector
            curr = curr->right; // And move to the next, which will be the right node
        }
        return ans;
    }
};
