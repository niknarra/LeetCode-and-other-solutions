class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans{-1, -1};
        int n = nums.size();
        int i = 0;

        while (i < n) {
            if (nums[i] != i + 1) {
                int correct = nums[i] - 1;
                if (nums[i] != nums[correct]) {
                    swap(nums[i], nums[correct]);
                } else {
                    i += 1;
                }
            } else {
                i += 1;
            }
        }
        for(int i=0;i<n;i+=1){
            if(nums[i] != i+1){
                ans[0] = nums[i];
                ans[1] = i + 1;
            }
        }

        return ans;
    }
};
