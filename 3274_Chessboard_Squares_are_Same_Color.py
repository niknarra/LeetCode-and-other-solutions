# Black Square = col + row => even
# White Square = col + row => odd

# TC: O(1) - standard arithmetic operations and checkerboard is usually of standard size 64

class Solution:
    def checkTwoChessboards(self, coordinate1: str, coordinate2: str) -> bool:
        
	def get_col_index(col: str) -> int: # Helper function to convert columns from char to int
        return ord(col) - ord('a') + 1
        
        s1_row = int(coordinate1[1])
        s1_col = get_col_index(coordinate1[0])
        
        s2_row = int(coordinate2[1])
        s2_col = get_col_index(coordinate2[0])
        
        return (s1_row + s1_col) % 2 == (s2_row + s2_col) % 2
	       # If both are odd or both are even, same color

