class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elemSum = accumulate(nums.begin(), nums.end(), 0);
        int digitSum = 0;

        for(int num:nums){
            while(num > 0){
                int digit = num % 10;
                digitSum += digit;
                num /= 10;
            }
        }

        return abs(elemSum - digitSum);
    }
};
