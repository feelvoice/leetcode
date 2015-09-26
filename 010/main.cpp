#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int pLen = p.length();
        if (pLen >= 2) {
            if (p[1] == '*') {
                while (s.length() && (p[0] == '.' || s[0] == p[0])) {    
                    if (isMatch(s, p.substr(2))) {
                        return true;
                    }
                    s = s.substr(1);
                }
                return isMatch(s, p.substr(2));
            }
            else {
                if (s.length()) {
                    return (p[0] == '.' || s[0] == p[0]) && isMatch(s.substr(1), p.substr(1));
                }
                else {
                    return false;
                }
            }
        }
        else if (pLen == 1) {
            if (s.length() != 1) return false;
            return p[0] == '.' || s[0] == p[0];
        }
        else {
            return s == "";
        }
    }
};

int main()
{
    Solution s = Solution();
    cout << s.isMatch("a", "a*a");
    return 0;
}