class Solution {
public:
    int averageValue(vector<int>& nums) {
        int count = 0;
        int sum = 0;

        for(auto num:nums){
            if(num%2 ==0 && num%3 == 0){
                count += 1;
                sum += num;
            }
        }

        return count!= 0 ? sum/count : 0;
    }
};
