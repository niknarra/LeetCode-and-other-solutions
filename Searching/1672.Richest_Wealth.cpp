class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int wealth = 0;

        for(int i=0;i<accounts.size();i+=1){
            int curr_wealth = 0;
            for(int j=0;j<accounts[i].size();j+=1){
                curr_wealth += accounts[i][j];
            }
            wealth = max(wealth, curr_wealth);
        }
        return wealth;
    }
};
