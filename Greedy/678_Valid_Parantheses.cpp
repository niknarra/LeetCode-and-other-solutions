// Greedy Approach using 2 Stacks
// TC: O(n) -> O(n + n)
// SC: O(n)

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st; // Stack to hold ) and (
        stack<int> ast; // Stack for *

        for(int i=0;i<s.size();i+=1){ // Loop through the string
            char curr = s[i];
	
	// In case of an open bracket, simply push to stack
            if(curr == '('){
                st.push(i); 
            }
	// In case of *, simply push to astack
            else if(curr == '*'){
                ast.push(i);
            }
	// In case of closing bracket,
            else{
	// Check if stack is not empty and balance with the opening bracket
                if(!st.empty()){
                    st.pop();
                }
	// If not, then check for a * that we can use as an opening bracket
                else if(!ast.empty()){
                    ast.pop();
                }
	// If we don't have a opening bracket and a * we can use, the string can never be valid
                else{
                    return false;
                }
            }
        }

	// Second pass to check if there are any leftover brackets in stack
        while(!st.empty() && !ast.empty()){
	// Check if the bracket is appearing after the *,
	// In this case, we return false as )( can't be valid
            if (st.top() > ast.top()) {
                return false;
            }
	// If not, pop both
            st.pop();
            ast.pop();
        }
    return st.empty(); // Return if the main stack is empty->balanced or not
    }
};
