# Greedy Approach
# TC: O(n)
# SC: O(1)

class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        
	# If the first bill itself is greater than 5, we won't have any bills to return change, so return false
	if bills[0] > 5:
            return False
        
	# Initialize five and ten counts
        fives, tens = 0,0

	# For each bill
        for bill in bills:
            # If bill is 5,
	    if bill == 5:
		# Simply add it to our five bill count
                fives += 1
	    # If bill is 10,
            elif bill == 10:
		# Check if we have atleast 1 5 bill for change
                if fives >= 1:
                    fives -= 1
                    tens += 1
		# If no 5s, return False
                else:
                    return False
	    # If bill is 20,
            else:
		# Greedily check if we can settle with least number of bills -> 1 5 and 1 10
                if tens >=1 and fives >=1:
                    fives -=1
                    tens -=1
		# In the worst case, check if we have 3 5s
                elif fives >=3:
                    fives -= 3
		# If not, return False
                else:
                    return False
	# Return true if no false cases were encountered
        return True
