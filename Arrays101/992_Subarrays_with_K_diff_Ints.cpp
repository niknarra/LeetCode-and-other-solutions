// Sliding Window Approach
// TC: O(n)
// SC: O(k)

class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        if (k < 0)
            return 0;

        unordered_map<int, int> mpp;
        int left = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right += 1) {
            mpp[nums[right]] += 1;

            while (mpp.size() > k) {
                mpp[nums[left]] -= 1;
                if (mpp[nums[left]] == 0) {
                    mpp.erase(nums[left]);
                }
                left += 1;
            }
            count += right - left + 1;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
