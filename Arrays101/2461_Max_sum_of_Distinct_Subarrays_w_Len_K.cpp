// Sliding Window Approach
// TC: O(n)
// SC: O(k)

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int left = 0;
        unordered_map<int, int> mpp;
        long long sum = 0;
        long long max_sum = 0;

        for (int right = 0; right < nums.size(); right += 1) {
            mpp[nums[right]] += 1;
            sum += nums[right];
	// Validate the window by making sure the map has more than k elements and also the len of window is more than k
            while (mpp.size() > k || right - left + 1 > k) {
                sum -= nums[left];
                mpp[nums[left]] -= 1;
                if (mpp[nums[left]] == 0) {
                    mpp.erase(nums[left]);
                }
                left += 1;
            }
	// Make sure the window size and map size are both equal to k before updating the sum
            if (mpp.size() == k && right - left + 1 == k) {
                max_sum = max(max_sum, sum);
            }
        }
        return max_sum;
    }
};
