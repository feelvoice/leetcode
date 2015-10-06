class Solution {
public:
    bool isScramble(string s1, string s2) { 
        int len1 = s1.length(), len2 = s2.length();
        if (len1 != len2) return false;
        if (len1 == 1) return s1[0] == s2[0];
        
        map<char, int> m1, m2;
        for (int i=0; i<len1; i++) ++m1[s1[i]];
        for (int i=0; i<len2; i++) ++m2[s2[i]];
        if (m1 != m2) return false;
        
        for (int i=1; i<len1; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                isScramble(s1.substr(i), s2.substr(i))) return true;
                
            if (isScramble(s1.substr(0, i), s2.substr(len1-i, i)) &&
                isScramble(s1.substr(i), s2.substr(0, len1-i))) return true;
        }
        return false;
    }
};