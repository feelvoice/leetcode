#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        
        int group = numRows != 1 ? 2 * numRows - 2 : 1;
        string ret = "";
        int len = s.length();
        for (int r=0; r<numRows; r++) {
            int cur = r;
            int sum = group;
            while (cur < len) {
                ret += s[cur];
                int other = sum - cur;
                if (r!=0 && r!=numRows-1 && other<len) {
                    ret += s[other];
                } 
                cur += group;
                sum += 2 * group;
            }
        }
        
        return ret;
    }
};


int main()
{
    Solution s = Solution();
    cout << s.convert("AAAA", 1) << endl;
}
