#include <iostream>
#include <map>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:  
    string minWindow(string s, string t) {
        int mt[256] = {0};
        int cur[256] = {0};
        int slen = s.length(), tlen = t.length();
        for (int i=0; i<tlen; i++) {
            ++mt[t[i]];
        }
        
        int ret = INT_MAX;
        int start, end;
        int i=0, j=0;
        int count = 0;
        while (j < slen) {
            ++cur[s[j]];
            if (cur[s[j]] <= mt[s[j]]) count++;
            j++;
            if (count == tlen) {
                do {
                    if (j - i < ret) {
                        ret = j - i;
                        start = i;
                        end = j;
                    }
                    --cur[s[i]];
                    if (cur[s[i]] < mt[s[i]]) count--;
                    i++;
                } while (count == tlen);
            }
        }
        if (ret == INT_MAX) return "";
        return s.substr(start, end-start);
    }
};

int main()
{
    Solution s = Solution();
    cout << s.minWindow("A", "AA");
    return 0;
}