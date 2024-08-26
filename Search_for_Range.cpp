class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        vector<int> ans = {-1,-1};
        
        while(low<=high){
            mid = (low+high)/2;
            
            if (nums[mid] == target){
                if (mid == 0 || nums[mid - 1] != target){
                    ans[0] = mid;
                    break;
                }
                else{
                    high = mid - 1;
                }
            }
            else if(nums[mid]<target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            
        }
        
        if (ans[0] == -1){
            return ans;
        }
        else{
        int low = ans[0];
        int high = nums.size()-1;
        int mid;
        
        while(low<=high){
            mid = (low+high)/2;
            
            if (nums[mid] == target){
                if (mid == nums.size() - 1 || nums[mid + 1] != target){
                    ans[1] = mid;
                    break;
                }
                else{
                    low = mid + 1;
                }
            }
            else if(nums[mid]<target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            
        }
        }
        return ans;
    }
};
