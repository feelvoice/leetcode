class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        typedef map<char, int> MAP;
        MAP mci;
        MAP::iterator it;
        
        int size = s.length();
        int ans = 0, head = 0;
        for (int i=0; i<size; i++) {
            it = mci.find(s[i]);
            if (it != mci.end()) {//found
                head = max(head, mci[s[i]] + 1);
            }
            ans = max(ans, i-head+1);
            mci[s[i]] = i;
        }
        
        return ans;
    }
};