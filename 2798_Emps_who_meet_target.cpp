class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans = 0;

        for(int hour:hours){
            if(hour >= target){
                ans += 1;
            }
        }
        return ans;
    }
};
