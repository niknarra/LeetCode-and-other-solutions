// Approach 1
// TC: O(n), SC: O(n)

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        string ans;

        for(int i=0; i<s.size(); i+=1){
            if(st.empty() || st.top().first != s[i]){
                st.push({s[i], 1});
            }
            else{
                st.top().second+=1;
            }

            if(!st.empty() && st.top().second == k){
                st.pop();
            }
        }

        while(!st.empty()){
            int count = st.top().second;
            for(int i=0;i<count;i+=1){
                ans += st.top().first;
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// Approach 2 - Slightly readable and cleaner code, same comps

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        // Traverse the string
        for (char c : s) {
            if (!st.empty() && st.top().first == c) {
                // Increment the count for the top character
                st.top().second++;
            } else {
                // Push a new character with count 1
                st.push({c, 1});
            }

            // Remove the group if the count reaches k
            if (st.top().second == k) {
                st.pop();
            }
        }

        // Build the result string
        string ans;
        while (!st.empty()) {
            ans.append(st.top().second, st.top().first); // Append `count` occurrences of `char`
            st.pop();
        }

        reverse(ans.begin(), ans.end()); // Reverse to correct the order

        return ans;
    }
};

