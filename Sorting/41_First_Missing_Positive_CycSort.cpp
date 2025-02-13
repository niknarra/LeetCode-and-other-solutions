class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while (i < n) {
            if (nums[i] > 0 && nums[i] <= n) {
                int correct = nums[i] - 1;
                if (nums[i] != nums[correct]) {
                    swap(nums[i], nums[correct]);
                }
                else{
                    i+=1;
                }
            }

            else {
                i += 1;
            }
        }
        for(int i=0;i<n;i+=1){
            if(nums[i] != i + 1) return i+1;
        }
        return n+1;
    }
};
