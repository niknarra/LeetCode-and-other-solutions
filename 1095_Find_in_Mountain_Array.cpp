/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int findPeak(MountainArray &mountainArr){
        int low = 0;
        int high = mountainArr.length()-1;

        while(low!=high){
            int mid = low + (high-low)/2;

            if(mountainArr.get(mid) > mountainArr.get(mid+1)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }

    int orderAgnosticBS(MountainArray &mountainArr, int begin, int stop, int target){
    	int start = begin;
    	int end = stop;
    
    	bool ascending = mountainArr.get(start) < mountainArr.get(end);
    
    	while(start<=end){
        int mid = start + (end-start)/2;
        
        if(mountainArr.get(mid) == target){
            return mid;
        }
        
        if(ascending){
            if(mountainArr.get(mid) < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        else{
            if(mountainArr.get(mid) < target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
    }
    return -1;
    
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length(); // Get length from api

        int peak = findPeak(mountainArr); // Get the peak element as it is a mountain array

        int leftResult = orderAgnosticBS(mountainArr, 0, peak, target); // First look from start to peak as this will be in ascending order

        if (leftResult != -1) { // If found, return the value
            return leftResult;
        }

        return orderAgnosticBS(mountainArr, peak + 1, n-1, target); // If not found, return the value from right half which can be index or -1 
    }
};
