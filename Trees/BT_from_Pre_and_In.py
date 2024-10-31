# Leetcode 105
# Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

# The root will always be the first element in the preorder vector

# Now that we know the root, from the inorder vector, everything on its left will be the left subtree and everything on the right will be right subtree

# Within this sub list, we can refer to the preorder list again to get the root, left and right

# This becomes a recursive process

# Approach 1
# O(N*N)

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
	if not preorder or not inorder: # If either of the lists is empty, we return None
		return None
	
	root = TreeNode(preorder[0]) # In preorder, the first element will always be the root
	mid = inorder.index(preorder[0]) # In inorder, the elements to the left of root will form left subtree and elements to the right will form right subtree, so we get the index of the root
	
	root.left = self.buildTree(preorder[1:mid+1], inorder[:mid])
	root.right = self.buildTree(preorder[mid+1:], inorder[mid+1:])
	
	return root 

# preorder[1:mid+1] -> 0th element is the root, so ignore it and from the 1st element, the mid number of elements will be the elements of the left subtree

# inorder[:mid] -> all the elements from 0 until the mid point will be elements of left subtree

# preorder[mid+1:] -> all the elements after mid number of elements will be right subtree elements

# inorder[mid+1:] -> all the elements to the right of root will be right subtree elements

# Approach 2
# O(N) - using hashmap

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
	inorder_map = {val: idx for idx, val in enumerate(inorder)}

        def build(pre_start: int, pre_end: int, in_start: int, in_end: int) -> Optional[TreeNode]:
            if pre_start > pre_end or in_start > in_end:
                return None
            
            root_val = preorder[pre_start]
            root = TreeNode(root_val)

            mid = inorder_map[root_val]

            left_size = mid - in_start

            root.left = build(pre_start + 1, pre_start + left_size, in_start, mid - 1)
            root.right = build(pre_start + left_size + 1, pre_end, mid + 1, in_end)

            return root

        return build(0, len(preorder)-1, 0, len(inorder)-1)	
