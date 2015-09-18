class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ss;
        for (int i=0; i<tokens.size(); i++) {
            if (tokens[i] == "+") {
                int a = ss.top(); ss.pop();
                int b = ss.top(); ss.pop();
                ss.push(a+b);
            }
            else if (tokens[i] == "-") {
                int a = ss.top(); ss.pop();
                int b = ss.top(); ss.pop();
                ss.push(b-a);
            }
            else if (tokens[i] == "*") {
                int a = ss.top(); ss.pop();
                int b = ss.top(); ss.pop();
                ss.push(a*b);
            }
            else if (tokens[i] == "/") {
                int a = ss.top(); ss.pop();
                int b = ss.top(); ss.pop();
                ss.push(b/a);
            }
            else {
                ss.push(atoi(tokens[i].c_str()));
            }
        }
        return ss.top();
    }
};