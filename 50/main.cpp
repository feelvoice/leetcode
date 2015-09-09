class Solution {
public:

    double myPow(double x, int n) {
        if (n < 0) {
            return 1.0 / x / myPow(x, -1-n);
        }
        else if (n == 0) return 1;
        else {
            double tmp = myPow(x, n/2);
            if (n % 2) {
                return x * tmp * tmp;
            }
            else {
                return tmp * tmp;
            }
        }
    }
};