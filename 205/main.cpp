class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m;
        map<char, char> rev;
        for (int i=0; i<s.length(); i++) {
            if (m.find(s[i]) != m.end()) {//found
                if (m[s[i]] != t[i]) return false;
            }
            else {
                m[s[i]] = t[i];
                if (rev.find(t[i]) != rev.end()) return false;
                rev[t[i]] = s[i];
            }
        }
        return true;
    }
};