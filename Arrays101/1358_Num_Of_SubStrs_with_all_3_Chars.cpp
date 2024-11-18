// Sliding Window Approach
// TC: O(n)
// SC: O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int count = 0;
        int cntA = 0, cntB = 0, cntC = 0;

        for (int right = 0; right < s.size(); right += 1) {
           // Identify curr character and increment its count
	    if (s[right] == 'a')
                cntA += 1;
            else if (s[right] == 'b')
                cntB += 1;
            else{
                cntC += 1;
            }
	
	// As long as the current window is valid, anything we add after it will also be valid
            while (cntA >= 1 && cntB >= 1 && cntC >= 1) {
	// So the count will be the total size - right pointer
                count += s.size() - right;
        // Adjust the window
                if (s[left] == 'a')
                    cntA -= 1;
                else if (s[left] == 'b')
                    cntB -= 1;
                else
                    cntC -= 1;
                
                left += 1;
            }

        }
        return count;
    }
};
