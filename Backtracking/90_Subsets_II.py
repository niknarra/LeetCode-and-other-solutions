class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        # To avoid duplicates, sort the nums so the duplicates will be adjacent
        nums.sort()

        # Initialize sets and vars for backtracking
        res, sol = [], []
        n = len(nums)

        # Recursive function
        def backtracker(start):
            # Base Case: If starting point is out of bounds, list has been traversed completely,
            # so return with whatever answer was formed in this path
            if start == n:
                res.append(sol[:])
                return
            
            # Explore the path by including the current index
            sol.append(nums[start])
            backtracker(start + 1)
            sol.pop() # Backtrack and undo what was done in this path

            # Skip the current index and make sure the next index is not the same as current index
            # while also making sure it is not out of bounds
            while start+1 < n and nums[start] == nums[start+1]:
                start += 1
            
            backtracker(start+1)
        
        backtracker(0)

        return res
