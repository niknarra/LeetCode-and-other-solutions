class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        while(low != high){ // At peak element, the high and low will point to the same element
            int mid = low + (high-low)/2;

             if(arr[mid]>arr[mid+1]){ // If mid value is greater than mid+1, we are on downward slope
                high = mid; // So mid could be a possible answer, set high to mid and not mid-1
            }
            else{
                low = mid + 1; // If not, we are on a upward slope so move to the right half
            }
        }
        return low; // As low and high are both pointing to same index, return any
    }
};
