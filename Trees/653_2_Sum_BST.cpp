// Approach 1 - Using inorder traversal
// TC: O(n) + O(n) -> Traversal + Loop
// SC: O(n) -> vector storing inorder

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& in_order){
        if(root == nullptr) return;

        inorder(root->left, in_order);
        in_order.push_back(root->val);
        inorder(root->right, in_order);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> in_order; 
        inorder(root, in_order); // Get the inorder

        int i = 0; // Setup two pointers to check the sum
        int j = in_order.size()-1;

        while(i<j){
            if(in_order[i] + in_order[j] == k) return true;

            else if(in_order[i] + in_order[j] > k){
                j -= 1;
            }

            else{
                i += 1;
            }
        }
        return false;
    }
};

// Approach 2 - Using 2 stacks and BST Iterator logic
// TC: O(n)
// SC: O(h) * 2

class Solution {
private:
    stack<TreeNode*> lst;
    stack<TreeNode*> rst;

    void pushAll(TreeNode* root, bool direction, stack<TreeNode*>& st){
        while (root) {
            st.push(root);
            root = direction ? root->left : root->right;
        }
    }
public:
    bool findTarget(TreeNode* root, int k) {
        TreeNode* i = next(root, true, lst);
        TreeNode* j = next(root, false, rst);

        while((i != j)){
            if(i->val + j->val == k){
                return true;
            }
            else if(i->val + j->val > k){
                j = next(j, false, rst);
            }
            else{
                i = next(i, true, lst);
            }
        }
        return false;
    }

    TreeNode* next(TreeNode* root, bool direction, stack<TreeNode*>& st){
        if (st.empty()) {
            pushAll(root, direction, st);
        }

        TreeNode* temp = st.top();
        st.pop();

        pushAll(direction ? temp->right : temp->left, direction, st);

        return temp;
    }
};
