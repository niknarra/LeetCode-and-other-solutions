# Approach 1 - 
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res, sol = [], []

        def backtracker():
            if len(sol) == k:
                res.append(sol[:])
                return
            
            for num in range(1, n+1):
                if num not in sol:
                    if sol and num > sol[-1]:
                        sol.append(num)
                        backtracker()
                        sol.pop()
                    elif not sol:
                        sol.append(num)
                        backtracker()
                        sol.pop()
        
        backtracker()

        return res

# Approach 2 -
# Cleaning up the logic to skip over duplicate combinations

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res, sol = [], []

        def backtracker(start):
            if len(sol) == k:
                res.append(sol[:])
                return
            
            for num in range(start, n+1):
                if num not in sol:
                    sol.append(num)
                    backtracker(num+1)
                    sol.pop()
        
        backtracker(1)

        return res
