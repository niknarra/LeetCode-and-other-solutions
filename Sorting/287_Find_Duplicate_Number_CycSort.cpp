// Approach 1 -> Sorting from 1->N using Cyclic Sort
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while(i<n){
            int correct = nums[i] - 1;

            if(nums[i] != nums[correct]){
                swap(nums[i], nums[correct]);
            }

            else i += 1;

        }
        return nums[n-1];
    }
};

// Approach 2 -> Still using cyclic sort, but returning duplicate earlier
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while (i < n) {
            if (nums[i] != i + 1) {
                int correct = nums[i] - 1;

                if (nums[i] != nums[correct]) {
                    swap(nums[i], nums[correct]);
                } else {
                    return nums[i];
                }
            }
            else
                i += 1;
        }
        return -1;
    }
};
