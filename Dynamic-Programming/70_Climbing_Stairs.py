// This problem is basically a variation of fibonacci

// Initial Approach - Make it work.
// TC: O(2^n)

class Solution:
    def climbStairs(self, n: int) -> int:
        if(n == 0 or n == 1):
            return 1

        return self.climbStairs(n-1) + self.climbStairs(n-2)

// Improved Approach - Make it optimal!

class Solution:

    def stairClimber(self, n: int, memo: Dict[int, int]) -> int:
        if(n == 0 or n == 1):
            return 1
        
        if memo.get(n,0) != 0:
            return memo[n]
        
        memo[n] = self.stairClimber(n-1, memo) + self.stairClimber(n-2, memo)

        return memo[n]

    def climbStairs(self, n: int) -> int:
        memo = {}

        return self.stairClimber(n, memo)

// TC: O(n)
