// Approach 1 - Kadane's Algorithm
// TC: O(n) SC: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN; // Initially let the max be some value, Int_min
        int currSum = 0;

        for(int num:nums){
            currSum += num; // Accumulate the sum

            if(currSum > maxSum) maxSum = currSum; // If currently accumulated sum is bigger, update

            if(currSum < 0) currSum = 0; // If current sum falls below 0, there is no need to use it, so reset the sum
        }

        return maxSum;
    }
};

// The algo, Kadane's Algorithm keeps track of the best subarray ending at each index.
