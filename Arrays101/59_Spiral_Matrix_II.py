# Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.
# Starting from top-left corner, fill numbers 1 to n*n in clockwise direction
# Approach: Similar to Spiral Matrix I, using 4 pointers (top,bottom,left,right)
# Initialize counter=1 and increment it while traversing in spiral order

class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        if not n:
            return [[]]

        ans = [ [0 for _ in range(n)] for _ in range(n) ]
        num = 1
        
        top = 0
        bottom = len(ans) - 1
        left = 0
        right = len(ans[0]) - 1

        while left <= right and top <= bottom:
            # Left to Right
            for i in range(left, right+1):
                ans[top][i] = num
                num += 1
            top += 1

            # Top to Bottom
            for i in range(top, bottom+1):
                ans[i][right] = num
                num += 1
            right -= 1

            # Right to Left
            if(top <= bottom):
                for i in range(right, left-1, -1):
                    ans[bottom][i] = num
                    num += 1
                bottom -= 1
            
            # Bottom to Top
            if(left <= right):
                for i in range(bottom, top-1, -1):
                    ans[i][left] = num
                    num += 1
                left += 1

        return ans
