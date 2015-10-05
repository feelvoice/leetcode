class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if (len1 + len2 != len3) return false;
        
        vector<vector<int> > dp(len1+1, vector<int>(len2+1));
        dp[0][0] = 1;
        for (int i=1; i<=len1; i++) {
            if (s1[i-1] == s3[i-1]) dp[i][0] = 1;
            else break;
        }
        for (int i=1; i<=len2; i++) {
            if (s2[i-1] == s3[i-1]) dp[0][i] = 1;
            else break;
        }
        
        for (int i=1; i<=len1; i++) {
            for (int j=1; j<=len2; j++) {
                if (s1[i-1] == s3[i+j-1] && dp[i-1][j]) {
                    dp[i][j] = 1;
                    continue;
                }
                if (s2[j-1] == s3[i+j-1] && dp[i][j-1]) {
                    dp[i][j] = 1;
                    continue;
                }
            }
        }
        return dp[len1][len2];
    }
};