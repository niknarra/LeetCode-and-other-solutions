// Approach 1
// TC: O(n) and SC: O(k)

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mpp;
        set<int> res;

        for(int i=0;i<s.size();i+=1){
            mpp[s[i]] += 1;
        }

        for(auto key: mpp){
            res.insert(key.second);
        }

        return res.size() == 1;

    }
};

// Approach 2
// Similar complexities, but avoids the set reducing SC

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mpp;
        int occurances = -1;

        for(int i=0;i<s.size();i+=1){
            mpp[s[i]] += 1;
        }

        for(auto key: mpp){
            if(occurances == -1){
                occurances = key.second;
            }
            else if(occurances != key.second){
                return false;
            }
        }

        return true;

    }
};
