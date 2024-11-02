// Approach 1 - Recursion
// TC and SC: O(N)

class Solution {
public:
    TreeNode* prev = nullptr;
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
    
        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};

// Approach 2 - Iterative
// As we push right and left, the top element will always be the left child
// So we first make the left child a right child and the right child the right right child
// TC and SC: O(N)

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr) return;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();

            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);

            if(!st.empty()){
                curr->right = st.top();
            }
            curr->left = nullptr;
        }

    }
};

// Approach 3 - Morris
// TC: O(N), SC: O(1)

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while(curr){
            if(curr->left){
                TreeNode* prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
        }
        curr = curr->right;
        }
    }
};
