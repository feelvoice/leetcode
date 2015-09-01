class Solution {
public:
    bool isValid(string s) {
        
        stack<char> sc;
        int len = s.length();
        char top;
        for (int i=0; i<len; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                sc.push(s[i]);
            }
            else {
                if (sc.empty()) return false;
                top = sc.top();
                sc.pop();
                if (s[i] == ')' && top == '(') continue;
                if (s[i] == ']' && top == '[') continue;
                if (s[i] == '}' && top == '{') continue;
                return false;
            }
        }
        return sc.empty();
    }
};