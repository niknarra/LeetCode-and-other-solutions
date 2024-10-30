class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	
	if(root == nullptr || root == p || root == q) return root; // Base Case

	TreeNode* left = lowestCommonAncestor(root->left, p ,q); // Recur over the left subtree
	TreeNode* right = lowestCommonAncestor(root->right, p ,q); // Recur over the right subtree

	if(left == nullptr) return right; // If left subtree is returning null, both p and q are not on the left so return right
	
	else if(right == nullptr) return left; // If not, return right
	
	else return root; // If both are not returning nullptrs, the root is the LCA!

}

// The structure of the function ensures that:

// If both left and right are non-null, root is returned as the common ancestor.
// If either left or right contains the ancestor, that non-null subtree pointer is returned.
// If both are nullptr, it simply returns nullptr.
