class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> ss, tt;
        for (int i=0; i<s.length(); i++) {
            ++ss[s[i]];
        }
        for (int i=0; i<t.length(); i++) {
            ++tt[t[i]];
        }
        return ss == tt;
    }
};