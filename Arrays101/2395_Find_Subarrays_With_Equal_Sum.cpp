// Sliding Window O(n) Approach

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int left = 0;
        int right = 0;
        unordered_set<int> sums;
        int sum = 0;

        while(right<nums.size()){
            sum += nums[right];

            if(right-left+1 == 2){
                if (sums.find(sum) != sums.end()) return true; 

                sums.insert(sum);
                sum -= nums[left];
                left += 1;
            }
            right += 1;
        }
        return false;
    }
};
