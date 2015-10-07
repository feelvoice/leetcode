class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        int idx = 0;
        
        int total = 0, cur = 0;
        int diff;
        for (int i=0; i<len; i++) {
            diff = gas[i] - cost[i];
            total += diff;
            if (cur < 0) {
                cur = diff;
                idx = i;
            }
            else {
                cur += diff;
            }
        }
        return total >= 0 ? idx : -1;
    }
};