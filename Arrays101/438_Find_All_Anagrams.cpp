// Approach 1 - Straight from my intuition
// Get the window, check if it is an anagram
// TLE; not efficient

class Solution {
public:
    bool isAnagram(unordered_map<char, int> mpp_s, unordered_map<char, int> mpp_p){
        for(auto &[key, value]: mpp_s){
            if (mpp_p.find(key) == mpp_p.end() || mpp_p[key] != value) {
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int left = 0;
        vector<int> ans;

        if (s.size() < p.size()) return ans;

        unordered_map<char, int> mpp_p;

        for(char ch:p){
            mpp_p[ch] += 1;
        }

        for(int right = 0;right<s.size();right+=1){

            if(right-left+1 == p.size()){
                unordered_map<char, int> mpp_s;
                for(int i=left;i<=right;i+=1){
                    mpp_s[s[i]] += 1;
                }
                if(isAnagram(mpp_s, mpp_p)){
                    ans.push_back(left);
                }
                left += 1;
            }
        }

        return ans;
    }
};

// Approach 2 - Similar intuition, but more optimized
// TC: O(n+m)
// SC: O(k); k-> number of distinct characters

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
	
	// Early return if string to be checked for anagrams is smaller than the anagram string
        if (s.size() < p.size())
            return ans;

        unordered_map<char, int> mpp_p, mpp_s;
	
	// Initialize the anagram string with it's frequencies
        for (char ch : p) {
            mpp_p[ch] += 1;
        }

        int left = 0;
        for (int right = 0; right < s.size(); right += 1) {

            mpp_s[s[right]]++;
		
	// If the current window is greater than the anagram string size,
            if (right - left + 1 > p.size()) {
		// Decrement the left most character's count
                mpp_s[s[left]]--;
	
		// If the character's count is 0, erase it from the map
                if (mpp_s[s[left]] == 0) {
                    mpp_s.erase(s[left]);
                }
	
		// Maintain the window size
                left++;
            }
	
	// If the current window is equal to the size of anagram string and the maps are equal
            if (right - left + 1 == p.size() && mpp_s == mpp_p) {
                ans.push_back(left); // Add the starting index, which would be left index
            }

        }
        return ans;
    }
};

