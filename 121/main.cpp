class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) return 0;
        
        int ret = 0;
        int cur = prices[0];
        for (int i=1; i<prices.size(); i++) {
            if (prices[i] > cur) {
                ret = max(ret, prices[i] - cur);
            }
            else {
                cur = prices[i];
            }
        }
        return ret;
    }
};