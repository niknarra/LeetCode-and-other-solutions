# LC Hard
# Pattern -> Get left max walls and right max walls and use two pointers to compare and get the max water that can be held

# Approach 1

class Solution:
    def trap(self, height: List[int]) -> int:
        leftMax, rightMax = 0, 0
        n = len(height)

        leftWalls = [0] * n
        rightWalls = [0] * n

        for i in range(n):
            leftWalls[i] = leftMax
            leftMax = max(leftMax, height[i])
        
        for i in range(n-1,-1,-1):
            rightWalls[i] = rightMax
            rightMax = max(rightMax, height[i])
        
        water = 0

        for i in range(n):
            currWater = min(leftWalls[i], rightWalls[i])

            water += max(0, currWater-height[i])

        return water

# Approach 2
# TC and SC: O(n)

class Solution:
    def trap(self, height: List[int]) -> int:
        # Initially left most and right most walls are non existent, so -> 0
        leftMax, rightMax = 0, 0
        n = len(height)

        # Initialize the max right walls and left walls as 0
        leftWalls = [0] * n
        rightWalls = [0] * n

        # Iterate over the array of heights
        # We can iterate from both directions in one go using below pointers,
        # i -> 0-n
        # j = -i - 1 -> If i = 1, j = -1 - 1 = -2 -> second from last
        for i in range(n):
            j = -i - 1

            # Assign current tallest left wall and then check if there is a taller wall
            leftWalls[i] = leftMax
            leftMax = max(leftMax, height[i])

            # Assign current tallest right wall and then check if there is a taller wall
            rightWalls[j] = rightMax
            rightMax = max(rightMax, height[j])
        
        water = 0

        # Final loop to calculate the water stored
        for i in range(n):
            # Get the potential or total amount of water that can be stored
            currWater = min(leftWalls[i], rightWalls[i])

            # Get the actual water that will be stored by removing the height
            # Use 0 to make sure the value never becomes negative
            water += max(0, currWater-height[i])

        return water
