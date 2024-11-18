// Optimal Approach
// TC: O(nums1 + nums2)
// SC: O(nums2)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> ans;
        unordered_map<int, int> all;
	// Get all NGEs
        for(int i=nums2.size()-1;i>=0;i-=1){

            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                all[nums2[i]] = st.top();
            }
            else{
                all[nums2[i]] = -1;
            }
            
            st.push(nums2[i]);
        }
	// Get the NGEs of numbers in nums1
        for(int num:nums1){
            ans.push_back(all[num]);
        }

        return ans;
    }
};
