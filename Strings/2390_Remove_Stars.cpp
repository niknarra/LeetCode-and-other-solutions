// Approach 1 - Using Stack
// TC and SC: O(n)

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for(char ch:s){
            if(ch != '*'){
                st.push(ch);
            }
            else{
                st.pop();
            }
        }

        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// Approach 2 - Using string as a dynamic stack
// Same comps but slightly more efficient as we're not using a stack

class Solution {
public:
    string removeStars(string s) {
        string ans;

        for(char ch:s){
            if(ch != '*'){
                ans += ch;
            }
            else{
                ans.pop_back();
            }
        }

        return ans;
    }
};
