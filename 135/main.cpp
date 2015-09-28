class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        if (len == 0) return 0;
        
        vector<int> dp(len, 1);
        for (int i=1; i<len; i++) {
            if (ratings[i] > ratings[i-1]) {
                dp[i] = dp[i-1] + 1;
            }
        }
        for (int i=len-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1]) {
                dp[i] = max(dp[i], dp[i+1]+1);
            }
        }
        int sum = 0;
        for (int i=0; i<len; i++) sum += dp[i];
        return sum;
    }
};