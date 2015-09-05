
class Solution {
public:
    void make_next(const string &needle, vector<int> &next) {
        next[0] = 0;
        int j = 0;
        for (int i=1; i<needle.length(); i++) {
            while (j>0 && needle[j] != needle[i]) {
                j = next[j-1];
            }
            if (needle[j] == needle[i]) {
                j++;
            }
            next[i] = j;
        }
    }
    
    int kmp(const string &needle, const string &haystack) {
        int n = haystack.length();
        int m = needle.length();
        if (m == 0) return 0;
        vector<int> next(m);
        make_next(needle, next);
        
        int j = 0;
        for (int i=0; i<n; i++) {
            while (j>0 && needle[j] != haystack[i]) {
                j = next[j-1];
            }
            if (needle[j] == haystack[i]) {
                j++;
            }
            if (j == m) return i-j+1;
        }
        return -1;
    }

    int strStr(string haystack, string needle) {    
        int ret = kmp(needle, haystack);
        return ret;
    }
};