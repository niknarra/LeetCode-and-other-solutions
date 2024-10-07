class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s==""){
            return true;
        }
        
        int i = 0;

        for(int j = 0;j<t.size();j+=1){
            if(i<s.size() && t[j]==s[i]){
                i += 1;
            }
        }

        if (i == s.size()) return true;

        return false;

    }
};
