class Solution {
public:
    string reverseOnlyLetters(string s) {
        string ans;
        int start = 0;
        int end = s.size()-1;

        while(start < end){
            if(!isalpha(s[start]) || !isalpha(s[end])){
                if(!isalpha(s[start])){
                    start += 1;
                }
                if(!isalpha(s[end])){
                    end -= 1;
                }
            }
            else{
                char temp;
                temp = s[start];
                s[start] = s[end];
                s[end] = temp;

                start += 1;
                end -= 1;
            }
        }

        return s;
    }
};
