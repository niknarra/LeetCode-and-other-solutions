// Binary Search
// TC: O(log n) SC: O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
  	// BS to find the first occurance
        vector<int> ans = {-1, -1};
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
	// Validate the mid is not just target, but the first occurance
            if (nums[mid] == target) {
                if (mid == 0 || nums[mid - 1] != target) {
                    ans[0] = mid;
                    break;
                } else {
                    high = mid - 1;
                }
            }

            else if (nums[mid] < target) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }
	
	// If the element is not found, simply return -1 -1 and exit
        if (ans[0] == -1) {
            return ans;
	// If not, then get the last occurance
        } else {
            low = ans[0];
            high = nums.size()-1;
            while (low <= high) {
                int mid = (low + high) / 2;

                if (nums[mid] == target) {
                    if (mid == nums.size() - 1 || nums[mid + 1] != target) {
                        ans[1] = mid;
                        break;
                    }
                    else{
                        low = mid + 1;
                    }
                } else if (nums[mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return ans;
    }
};
