class Solution {
public:
    int reverse(int x) {
        int sign = x >= 0 ? 1 : -1;
        long long ret = 0, xx = abs(x);
        
        while (xx) {
            ret = ret * 10 + xx % 10;
            xx /= 10;
        }
        
        ret = sign * ret;
        if (ret > INT_MAX || ret < INT_MIN) return 0;
        return ret;
    }
};