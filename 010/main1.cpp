#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') return *s == '\0';
        if (*(p+1) != '*') {
            return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
        }
        while ((*p == *s) || (*p == '.' && *s != '\0')) {
            if (isMatch(s, p+2)) return true;
            s++;
        }
        return isMatch(s, p+2);
    }

    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }
};

int main()
{
    Solution s = Solution();
    cout << s.isMatch("a", "a*a");
    return 0;
}