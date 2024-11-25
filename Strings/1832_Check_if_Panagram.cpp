class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.size() < 26) return false;

        unordered_set<char> chars;

        for(char ch:sentence){
            chars.insert(ch);
        }
        
        return chars.size() == 26 ? true : false;
    }
};
