class Solution {
public:
    int sumOfMultiples(int n) {
        int ans = 0;

        for(int i=1;i<=n;i+=1){
            if(i%3 == 0) ans += i;
            else if (i%5 == 0) ans += i;
            else if (i%7 == 0) ans += i;
        }

        return ans;
    }
};
