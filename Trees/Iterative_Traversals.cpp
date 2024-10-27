// Iterative DFS Traversals

// Pre-Order
// Approach 1 - Using Stack

#include<stack>
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        if(root == nullptr){
            return ans;
        }

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            ans.push_back(curr->val);

            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
        }
        return ans;
    }
};

// Here we use a stack for it's LIFO property and for the same reason, we push the right first and left second.

// Approach 2 - Using Deque

#include<deque>
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        if(root == nullptr){
            return ans;
        }

        deque<TreeNode*> q;
        q.push_back(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop_front();
            ans.push_back(curr->val);

            if(curr->right) q.push_front(curr->right);
            if(curr->left) q.push_front(curr->left);
        }
        return ans;
    }
};

// Both have same TC and SC of O(n). Stack is usually preferred but deque can also be used.

// In-Order

#include<stack>
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        if(root == nullptr) return ans;

        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(curr != nullptr || !st.empty()){ // As long as the stack is not empty or the current node is not null

            while(curr!=nullptr){ // while the current node is not null,
                st.push(curr); // Push the node to the top of stack
                curr = curr->left; // And move to the left
            }

            curr = st.top(); // Once curr becomes nullptr and loop is broken, reassign curr to the top most element from st
            st.pop(); // Pop it
            ans.push_back(curr->val); // And push it to the ans vector

            curr = curr->right; // Now we handle the right
        }
        return ans;
    }
};

// Post-Order
// Approach 1 - Using 2 Stacks

#include<stack>
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;

        if(root == nullptr) return res;

        stack<TreeNode*> st;
        stack<TreeNode*> ans;

        st.push(root);

        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            ans.push(curr);
            
            if(curr->left) st.push(curr->left);
            if(curr->right) st.push(curr->right);
        }

        while(!ans.empty()){
            res.push_back(ans.top()->val);
            ans.pop();
        }
        return res;
    }
};

// Whenever we pop the top the element from the main stack, we push it to our helper stack.
// As we push left first and right next to the main stack, the answer will be reversed in the helper stack
// But as we push back to result vector top to bottom, the order is corrected
