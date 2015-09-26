/*
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
*/

class Solution {
public:

    string preProcess(const string &s) {
        int n = s.length();
        if (n == 0) return "^$";
        string ret;
        for (int i=0; i<n; i++) {
            ret += "#";
            ret += s[i];
        }
        return "^" + ret + "#$";
    }

    string longestPalindrome(string s) {
        string T = preProcess(s);
        int n = T.length();
        vector<int> P(n);
        int C=0, R=0;

        for (int i=1; i<n-1; i++) {//skip ^$
            int mirror = C - (i-C);
            P[i] = (R > i) ? min(R-i, P[mirror]) : 0;
            while (T[i+1+P[i]] == T[i-1-P[i]]) {
                P[i]++;
            }
            if (i+P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
        
        int maxLen = 0;
        int centerIndex = 0;
        for (int i=1; i<n-1; i++) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }

        return s.substr((centerIndex-1-maxLen)/2, maxLen);
    }
};
/*
int main() {
    Solution s = Solution();
    string n = s.longestPalindrome("abaaba");
    printf("%s\n", n.c_str());
    return 0;
}
*/
