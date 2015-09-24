class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        int ret = 0;
        while (num) {
            ret += num % 10;
            num /= 10;
        }
        return (ret % 9 == 0) ? 9 : ret % 9;
    }
};