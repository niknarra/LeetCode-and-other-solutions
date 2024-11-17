# Sliding Window Approach
# TC: O(n)
# SC: O(n)

class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        basket = {}
        count = 0
        left = 0
        right = 0
        max_len = 0

        while right < len(fruits):
	#If fruit is already in basket, inc the count. If not, add it to the basket 
            basket[fruits[right]] = basket.get(fruits[right], 0) + 1
            
	# If there are more than 2 fruits in the basket, we need to remove the first fruit in the basket
            if len(basket) > 2:
                while len(basket) > 2:
                    fruit_to_remove = fruits[left] # Get the key 
                    basket[fruit_to_remove] -= 1  # Decrement the count of the first most fruit by one
                    if basket[fruit_to_remove] == 0: # If the fruit is completely removed,
                        del basket[fruit_to_remove] # Delete it as we are no longer storing it
                    left += 1 # Move the left pointer by 1 to get to the next fruit

            max_len = max(max_len, right-left+1) # Store the max length
            right += 1 # Increase the window size by 1

        return max_len

