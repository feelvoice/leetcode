class Solution {
public:

    int C(int n, int m) {
        long long ret = 1;
        if (m > n/2) m = n - m;
        
        int cur = m;
        for (int i=0; i<m; i++) {
            ret *= (n-i);
            while (cur && (ret % cur == 0)) {
                ret /= cur;
                cur--;
            }
        }
        return ret;
    }

    vector<int> getRow(int rowIndex) {
        vector<int> ret;
        for (int i=0; i<=rowIndex; i++) {
            ret.push_back(C(rowIndex, i));
        }
        return ret;
    }
};