class Solution {
public:
    long long no_sign_divide(long long ndividend, long long ndivisor) {
        if (ndividend < ndivisor) return 0;
        long long p=1;
        long long old_divisor = ndivisor;
        while ((ndivisor << 1) <= ndividend) {
            p <<= 1;
            ndivisor <<= 1;
        }
        long long ans = p + no_sign_divide(ndividend-ndivisor, old_divisor);
        return ans;
    }

    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        long long ndividend = abs((double)dividend);
        long long ndivisor  = abs((double)divisor);

        int sign = (dividend>=0 && divisor>=0 || dividend<0 && divisor<0) ? 1 : -1;
        long long ans = no_sign_divide(ndividend, ndivisor);
        ans *= sign;
        
        if (ans > INT_MAX || ans < -INT_MAX-1) return INT_MAX;
        return ans;
    }
};