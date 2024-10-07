class Solution:

    def getColumn(self, column:str) -> int:
        col = ord(column) - ord('a') + 1

        return col

    def squareIsWhite(self, coordinates: str) -> bool:
        row = int(coordinates[1])
        col = self.getColumn(coordinates[0])

        return (row+col) %2 != 0
