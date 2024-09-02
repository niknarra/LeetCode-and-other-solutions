class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        times = 0
        start_time = customers[0][0]
        for customer in customers:
            if customer[0] > start_time:
                start_time = customer[0]
            time_taken = start_time + customer[1]
            times += (time_taken - customer[0])
            start_time = time_taken 
        
        return times/len(customers)
