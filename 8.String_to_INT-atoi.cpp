class Solution {
public:
    int myAtoi(string s) {

        long long ans = 0;
        int i = 0;
        int sign = 1;
        int n = s.size();

        while (i < n && s[i] == ' ') {
            i += 1;
        }

        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-') {
                sign *= -1;
            }
            i += 1;
        }

        while (i < n && isdigit(s[i])) {
            if (ans > (INT_MAX - (s[i] - '0')) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            ans = (ans * 10) + (s[i] - '0');
            i += 1;
        }

        ans *= sign;

        return ans;
    }
};
