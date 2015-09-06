#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        vector<int> dp(len, 0);
        
        int ret = 0, cur;
        for (int i=0; i<len; i++) {
            if (s[i] == ')') {
                cur = 0;
                if (i-1 >= 0) {
                    int prev = i - dp[i-1] - 1;
                    if (prev >= 0 && s[prev] == '(') {
                        cur = dp[i-1] + 2;
                        prev -= 1;
                        if (prev >= 0) {
                            cur += dp[prev];
                        }
                    }
                    
                    dp[i] = cur;
                    ret = max(ret, cur);
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution s = Solution();
    cout << s.longestValidParentheses("()()))))()()(");
    return 0;
}