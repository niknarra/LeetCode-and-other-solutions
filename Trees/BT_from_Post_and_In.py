# Approach 1
# O(N*N)

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
	if not inorder or not postorder:
		return None
	
	root = TreeNode(postorder[-1])
	mid = inorder.index(postorder[-1])
	
	root.left = self.buildTree(inorder[:mid], postorder[:mid])
	root.right = self.buildTree(inorder[mid+1:], postorder[mid:-1])
	
	return root

# Approach 2
# O(N)

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        inorder_map = {val:idx for idx, val in enumerate(inorder)}

        def build(in_start: int, in_end: int, post_start: int, post_end: int):
            if in_start > in_end or post_start > post_end:
                return None
            
            root_val = postorder[post_end]
            root = TreeNode(root_val)

            mid = inorder_map[root_val]

            size_left = mid - in_start

            root.left = build(in_start, mid-1, post_start, post_start + size_left - 1)
            root.right = build(mid+1, in_end, post_start+size_left, post_end-1)

            return root
        
        return build(0, len(inorder)-1, 0, len(postorder)-1)

# The index function lookup for mid in the inorder list takes o(n), so we removed that by using a hashmap that has values and indexes mapped
