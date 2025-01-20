// Greedy Approach -> O(1)

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;

        int ones = min(numOnes, k);
        k -= ones;

        int zero = min(numZeros, k);
        k -= zero;

        int negs = min(numNegOnes, k);

        return ones-negs;
    }
};

// Iterative Approach -> O(k)

class Solution:
    def kItemsWithMaximumSum(self, numOnes: int, numZeros: int, numNegOnes: int, k: int) -> int:
        ans = 0

        while k > 0:
            if numOnes > 0:
                ans += 1
                numOnes -= 1
            
            elif numZeros > 0:
                ans += 0
                numZeros -= 1
            
            elif numNegOnes > 0:
                ans -= 1
                numNegOnes -= 1

            k -= 1
        
        return ans
