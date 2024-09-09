class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        mini = prices[0]

        for i in range(len(prices)):
            cost = prices[i] - mini
            max_profit = max(max_profit, cost)
            mini = min(mini, prices[i])
        
        return max_profit
        
