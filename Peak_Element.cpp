class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        
        if(nums.size()==1){
            return 0;
        }
        else if(nums[high] > nums [high-1]){
            return high;
        }
        else if (nums[low] > nums[low+1]){
            return 0; 
        }
        
        while(low<=high){
            mid = (low+high)/2;
            
            if ((mid == 0 || nums[mid] > nums[mid - 1]) && 
                (mid == nums.size() - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
            }
            if (nums[mid]<nums[mid+1]){
                low = mid + 1;
            }else{
                high = mid -1 ;
            }
        }
        return low;
    }
};
