// Recursive Approach

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0; // If root is null, tree is empty!
        
  	// If left subtree doesn't exist, the min depth has to be right subtree's depth + root(1)
        if (root->left == nullptr) return 1 + minDepth(root->right);  
	// Similarly, if right doesn't exist, min depth has to be whatever left subtree returns + root(1)
        if (root->right == nullptr) return 1 + minDepth(root->left);

        return 1 + min(minDepth(root->left), minDepth(root->right)); // In case, both are present we get the minimum
    }
};

// We have to check for left and right subtrees unlike max depth because, in max depth the max function naturally ignores the minimum depth for cases that return 0. Here if we don't process one child being absent, the absent child will always return 0 and the answer will always be 2.

// Iterative Approach

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int depth = q.front().second;
            q.pop();

            if(curr->left == nullptr && curr->right == nullptr){
                return depth;
            }

            if(curr->left) q.push({curr->left, depth+1});
            if(curr->right) q.push({curr->right, depth+1});

        }
        return 0;
    }
};
