class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, n+1);
        for (int i=1; i*i<=n; i++) {
            dp[i*i] = 1;
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; i+j*j<=n; j++) {
                dp[i+j*j] = min(dp[i+j*j], dp[i]+1);
            }
        }
        return dp[n];
    }
};