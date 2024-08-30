class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0;
        int i = 0;
        int n = nums.size();
        int temp;

        while(i<n){
            if(nums[i]!=0){
                temp = nums[lastNonZeroFoundAt];
                nums[lastNonZeroFoundAt] = nums[i];
                nums[i] = temp;
                lastNonZeroFoundAt += 1;
            }
            i += 1;
        }
    }
};
