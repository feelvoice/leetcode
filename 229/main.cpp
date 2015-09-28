class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        int len = nums.size();
        int m, n, cm=0, cn=0;
        for (int i=0; i<len; i++) {
            if (cm == 0) {
                m = nums[i];
                cm++;
            }
            else if (m == nums[i]) {
                cm++;
            }
            else if (cn == 0) {
                n = nums[i];
                cn++;
            }
            else if (n == nums[i]) {
                cn++;
            }
            else {
                cm--, cn--;
            }
        }
        int count_m = 0, count_n = 0;
        for (int i=0; i<len; i++) {
            if (cm && nums[i] == m) {
                count_m++;
            }
            else if (cn && nums[i] == n) {//else is indispensible..
                count_n++;
            }
        }
        if (count_m > len/3) ret.push_back(m);
        if (count_n > len/3) ret.push_back(n);
        return ret;
    }
};