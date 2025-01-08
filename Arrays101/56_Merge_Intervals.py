# Optimal Approach
# TC: O(n logn)
# SC: O(n)

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        merged = []
	
	# Sort the intervals by their first value
        intervals.sort(key = lambda interval:interval[0])
	
        for interval in intervals:
	# If the list is empty or if there is no overlap,
	# i.e., if the current interval begins after the last interval in the list
	# No need to merge, we can simply append it to the list
            if not merged or merged[-1][1] < interval[0]:
                merged.append(interval)
        # If not, there is an overlap and we need to merge.
	# When we are merging, the logic is simple, the starting point will remain the same
	# We need to get the maximum of the ending values
	    else:
                merged[-1] = [merged[-1][0], max(merged[-1][1], interval[1])]
        
        return merged
