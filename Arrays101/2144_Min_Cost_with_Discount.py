class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        if len(cost) < 3:
            return sum(cost)
        
        total_sum = 0

        cost.sort(reverse=True)

        for i in range(0,len(cost),3):
            if i+1 < len(cost):
                total_sum += cost[i] + cost[i+1]
            else:
                total_sum += cost[i]

        return total_sum
