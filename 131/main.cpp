class Solution {
public:

    bool isPalindrome(const string &s) {
        int i=0, j=s.length()-1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }

    void dfs(string s, vector<string> &cur, vector<vector<string> > &ret) {
        if (s.length() == 0) {
            ret.push_back(cur);
            return;
        }
        for (int i=1; i<=s.length(); i++) {
            string sub = s.substr(0, i);
            if (isPalindrome(sub)) {
                cur.push_back(sub);
                dfs(s.substr(i), cur, ret);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        vector<string> cur;
        dfs(s, cur, ret);
        return ret;
    }
};