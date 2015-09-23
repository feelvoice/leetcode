class Solution {
public:

    int cal(int n) {
        int ret = 0, digit;
        while (n) {
            digit = n % 10;
            ret += digit * digit;
            n /= 10;
        }
        return ret;
    }

    bool isHappy(int n) {
        map<int, int> m;
        do {
            if (n == 1) return true;
            if (m.find(n) != m.end()) return false;
            m[n] = 1;
            n = cal(n);
        } while (1);
    }
};