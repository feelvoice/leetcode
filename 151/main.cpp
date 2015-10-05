#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    void single_rev(string &s, int start, int end) {
        int i=start, j=end;
        while (i < j) {
            swap(s[i], s[j]);
            i++, j--;
        }
    }

    void myreverse(string &s, int start, int end) {
        int begin = 0;
        for (int i=start; i<=end; i++) {
            if (s[i] != ' ') {
                if (begin < 0) begin = i;
                if (i == end) {
                    single_rev(s, begin, end);
                }
            }
            else {
                single_rev(s, begin, i-1);
                begin = -1;
            }
        }
        single_rev(s, start, end);
    }

    void reverseWords(string &s) {
        int len = s.length();
        int cur = 0;
        bool leading = true, multi = false, need = false;
        for (int i=0; i<len; i++) {
            if (s[i] == ' ') {
                if (leading) continue;
                else {
                    if (multi) continue;
                    else {
                        multi = true;
                        need = true;
                    }
                }
            }
            else {
                if (need) s[cur++] = ' ';
                s[cur++] = s[i];
                leading = false;
                multi = false;
                need = false;
            }
        }
        myreverse(s, 0, cur-1);
        s.resize(cur);
    }
};

int main()
{
    Solution s = Solution();
    string one = "hi!";
    s.reverseWords(one);
    cout << one << endl;
    return 0;
}