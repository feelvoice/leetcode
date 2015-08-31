class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        long long ret = 0;
        
        bool is_begin = false;
        int sign = 1;
        bool sign_mark = false;
        int cur = -1;
        while (++cur < len) {
            if (str[cur] == ' ' && !is_begin) continue;
            is_begin = true;
            if (str[cur] == '+') {
                if (sign_mark) return 0;
                sign = 1;
                sign_mark = true;
            }
            else if (str[cur] == '-') {
                if (sign_mark) return 0;
                sign = -1;
                sign_mark = true;
            }
            else if (!isdigit(str[cur])) {
                break;
            }
            else {
                ret = ret * 10 + str[cur] - '0';
                if (ret * sign > INT_MAX) return INT_MAX;
                else if (ret * sign < INT_MIN) return INT_MIN;
            }  
        }
        return ret * sign;
    }
};