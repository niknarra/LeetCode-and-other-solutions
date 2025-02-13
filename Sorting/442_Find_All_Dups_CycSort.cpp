// Approach 1
// TC: O(n * k) k-> finding duplicates in answer vector

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int> ans;

        while(i<n){
            if (nums[i] != i + 1){
                int correct = nums[i] - 1;

                if(nums[i] != nums[correct]){
                    swap(nums[i], nums[correct]);
                }
                else{
                    if(find(ans.begin(), ans.end(), nums[i]) == ans.end()){
                        ans.push_back(nums[i]);
                    }
                    i += 1;
                }
            }
            else{
                i += 1;
            }
        }
        return ans;
    }
};

// Approach 2
// TC: O(n) and SC:O(k)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int> ans;

        while (i < n) {
            int correct = nums[i] - 1;

            if (nums[i] != nums[correct]) {
                swap(nums[i], nums[correct]);
            } else {
                i += 1;
            }
        }

        for (int i = 0; i < n; i += 1) {
            if (nums[i] != i + 1) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};
