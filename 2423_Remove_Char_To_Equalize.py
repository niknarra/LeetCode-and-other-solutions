# Approach 1 - Not the most optimal, but the most simplest
# Too many edge cases and tricky question, marked for optimizing later
# TC: O(n*n) SC:O(k) or O(n) if all characters are unique 

class Solution:
    def equalFrequency(self, word: str) -> bool:
        counts = {}

        # Get the frequencies
        for ch in word:
            counts[ch] = counts.get(ch, 0)+1
        
        # Iterate over each character of the word
	# Decrement the ith character by 1 and see if it's removed from the hash
	# If removed or not, check if all the count values are same and return
        for i in range(len(word)):
            curr_counts = counts.copy()
            curr_counts[word[i]] -= 1
            
            if curr_counts[word[i]] == 0:
                del[curr_counts[word[i]]]
            
            if(len(set(curr_counts.values())) == 1):
                return True
        
        return False

