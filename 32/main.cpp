class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        stack<int> si;
        si.push(-1);
        
        int ret = 0;
        for (int i=0; i<len; i++) {
            if (s[i] == '(') {
                si.push(i);
            }
            else {//')'
                if (si.size() > 1) {//we have a '(' match
                    si.pop();
                    int tmp = si.top();
                    ret = max(ret, i-tmp);
                }
                else {
                    si.pop();
                    si.push(i);
                }
            }
        }
        
        return ret;
    }
};