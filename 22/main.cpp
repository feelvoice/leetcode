class Solution {
public:
    void dfs(int left, int right, string cur, vector<string> &ret) {
        if (left == 0) {
            cur.append(right, ')');
            ret.push_back(cur);
            return;
        }
        dfs(left-1, right, cur+"(", ret);
        if (left < right) {
            dfs(left, right-1, cur+")", ret);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        dfs(n, n, "", ret);
        return ret;
    }
};