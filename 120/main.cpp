class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size();
        if (len == 0) return 0;
        
        vector<int> dp(len);
        for (int i=0; i<len; i++) {
            for (int j=i; j>=0; j--) {
                if (j == i) {
                    dp[j] = dp[j-1] + triangle[i][j]; 
                }
                else if (j == 0) {
                    dp[j] = dp[j] + triangle[i][j];
                }
                else {
                    dp[j] = min(dp[j], dp[j-1]) + triangle[i][j]; 
                }
            }
        }
        
        int ret = dp[0];
        for (int i=1; i<len; i++) {
            ret = min(ret, dp[i]);
        }
        return ret;
    }
};