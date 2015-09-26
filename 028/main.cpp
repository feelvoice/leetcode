class Solution {
public:
    int strStr(string haystack, string needle) {
        int hlen = haystack.length();
        int nlen = needle.length();
        
        for (int i=0, j; i<=hlen-nlen; i++) {
            for (j=0; j<nlen; j++) {
                if (needle[j] != haystack[i+j]) break;
            }
            if (j == nlen) return i;
        }
        return -1;
    }
};