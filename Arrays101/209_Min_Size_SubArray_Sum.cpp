// Sliding Window Approach
// TC: O(n)
// SC: O(1)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int curr_sum = 0;
        int min_len = INT_MAX;
        int curr_len = 0;

        for(int right=0; right<nums.size(); right+=1){
            curr_sum += nums[right];

            while(curr_sum >= target){
                curr_len = (right-left+1);
                min_len = min(min_len, curr_len);
                curr_sum -= nums[left];
                left+=1;
            }

        }

        return min_len == INT_MAX ? 0 : min_len;
    }
};
