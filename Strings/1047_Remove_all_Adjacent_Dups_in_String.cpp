// Approach 1 - Using a stack and reconstructing the string
// TC: O(n)
// SC: O(n)

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans= "";
        for(int i=0;i<s.size();i+=1){
            if(st.empty() || st.top() != s[i]){
                st.push(s[i]);
            }
            else if(st.top() == s[i]){
                st.pop();
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// Approach 2 - Using the given string as a dynamic stack and updating in-place
// Same TC and SC, but slightly more efficient

class Solution {
public:
    string removeDuplicates(string s) {
        string res;

        for(auto ch:s){
            if(!res.empty() && res.back() == ch){
                res.pop_back();                
            }
            else{
                res.push_back(ch);
            }
        }
        return res;
    }
};
