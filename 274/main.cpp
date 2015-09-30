class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        vector<int> m(len+1);
        for (int i=0, cur; i<len; i++) {
            cur = citations[i];
            if (cur > len) cur = len;
            m[cur]++;
        }
        int sum = 0;
        for (int i=len; i>=0; i--) {
            sum += m[i];
            if (sum >= i) return i;
        }
    }
};