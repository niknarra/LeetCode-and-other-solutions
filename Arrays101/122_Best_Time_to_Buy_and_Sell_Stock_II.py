class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0 # Let the initial profit be 0

	# Pretty straight forward approach
	# We just have to find the upward curves and sum them
	# If today's cost is greater than yesterday's, we sell today and buy yesterday
	# This works because we know tomorrow's cost
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                profit += (prices[i] - prices[i - 1])
        
        return profit

# TC: O(n) -> Single pass
# SC: Constant
