class Solution {
public:
    int countPrimes(int n) {
        vector<bool> mark(n, true);
        
        int ret = 0;
        for (int i=2; i<n; i++) {
            if (mark[i]) {
                ret++;
                for (int j=i; (long long)i*j<n; j++) {
                    mark[i*j] = false;
                }
            }
        }
        return ret;
    }
};