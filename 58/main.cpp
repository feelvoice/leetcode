class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int ret = 0;
        
        bool trailing_space = true;
        for (int i=len-1; i>=0; i--) {
            if (s[i] == ' ') {
                if (trailing_space) continue;
                else break;
            }
            ret++;
            trailing_space = false;
        }
        return ret;
    }
};