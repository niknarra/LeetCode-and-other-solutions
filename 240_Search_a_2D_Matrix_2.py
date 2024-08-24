# Brute - O(MxN)

   def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for row in matrix:
            for value in row:
                if value == target:
                    return True
        return False

# Better - Bin Search - O(MlogN)

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for row in matrix:
            low = 0
            high = len(row) - 1
            while(low<=high):
                mid = (low+high)//2

                if row[mid] == target:
                    return True
                elif row[mid] > target:
                    high = mid - 1
                else:
                    low = mid + 1
        return False

# Optimal - Staircase Approach - O(M+N)

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])

        first = matrix[0][0]
        last = matrix[m-1][n-1]

        if first == target or last == target:
            return True
        else:
            row = 0
            col = n - 1

            while row < m and col >= 0:
                if matrix[row][col] == target:
                    return True
                elif matrix[row][col] < target:
                    row += 1
                else:
                    col -= 1
        
        return False
