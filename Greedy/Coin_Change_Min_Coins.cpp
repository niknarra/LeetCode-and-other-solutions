// Approach 1 - Greedy
// TC: O(coins*log(coins))+O(S)
// SC: O(1)SC

// But this might not work i.e., consider using smaller denominations to reach the answer.

class Solution {

  public:
    int minCoins(vector<int> &coins, int sum) {
        
        if(sum == 0) return 0;
        
        sort(coins.rbegin(), coins.rend());
        
        int i = 0;
        int total_coins = 0;
        
        while(sum > 0 && i < coins.size()){
            if(coins[i] <= sum){
                sum = sum - coins[i];
                total_coins += 1;
            }else{
                i += 1;
            }
        }
        return sum==0 ? total_coins : -1;
    }
};

// Approach 2 - DP
// TC: O(sum×coins.size())
// SC: O(sum)

class Solution {
public:
    int minCoins(vector<int> &coins, int sum) {
        vector<int> dp(sum + 1, INT_MAX); // Initialize the DP vector of size sum with INT_MAX
        dp[0] = 0; // Base case: 0 coins needed to make sum 0

        for (int s = 1; s <= sum; ++s) { // Loop until we reach the sum
            for (int coin : coins) { // For each sum, find the num of coins
                // If current sum is greater than or eq to current coin and current sub-prblm is solved,
		if (s >= coin && dp[s - coin] != INT_MAX) {
                    dp[s] = min(dp[s], dp[s - coin] + 1); // Get the min number of coins
                }
            }
        }

        return dp[sum] == INT_MAX ? -1 : dp[sum]; // Return the ans if the sum is formed, it not -1
    }
};

