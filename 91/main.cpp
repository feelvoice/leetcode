#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if (len == 0) return 0;
        if (len == 1) return s[0] >= '1' && s[0] <= '9';
        
        vector<int> dp(len+1);
        dp[len] = 1;
        dp[len-1] = (s[len-1]>='1' && s[len-1]<='9') ? 1 : 0;
        for (int i=len-2; i>=0; i--) {
            if (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')) {
                dp[i] = dp[i+1] + dp[i+2];
            }
            else if (s[i] == '0') {
                dp[i] = 0;
            }
            else {
                dp[i] = dp[i+1];
            }
        }
        return dp[0];
    }
};

int main()
{
    Solution s = Solution();
    cout << s.numDecodings("10") << endl;
    return 0;
}