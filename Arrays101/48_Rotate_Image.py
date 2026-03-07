class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # The rotation basically breaks down into 
        # transpose + row reversal

        # Do the transpose first
        for row in range(len(matrix)):
            for col in range(row, len(matrix)):
                # We do range(row, len(matrix)) because we only want to swap upper triangle
                # If not, we endup swapping first and then reswaping again
                # essentially leaving the array as is
                matrix[row][col], matrix[col][row] = matrix[col][row], matrix[row][col]
        
        # Reverse each row
        for row in matrix:
            row.reverse()
