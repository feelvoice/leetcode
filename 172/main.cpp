class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        long long cur = 5;
        
        while (n >= cur) {
            ret += n / cur;
            cur *= 5;
        }
        return ret;
    }
};