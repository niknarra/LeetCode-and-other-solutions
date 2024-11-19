// Sliding Window Approach
// TC: O(n)
// SC: O(1)

class Solution {
public:
	// Helper Function to calculate subarrays with sum of atmost k
    int atMost(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int left = 0;
        int count = 0;
        int curr_sum = 0;

         for(int right=0;right<nums.size();right+=1){
            curr_sum += nums[right];

            while(curr_sum > goal){
                curr_sum -= nums[left];
                left += 1;
            }

            count += right-left+1;
         }
         return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
	// To get exactly k, we can get it by atmost k - atmost k-1
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
};

