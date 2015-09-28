class Solution {
public:

    void dfs(int next, int k, int n, vector<int> &cur, vector<vector<int> > &ret) {
        if (n < 0) return;
        if (n == 0 && k != 0) return;
        if (k == 0) {
            if (n == 0) {
                ret.push_back(cur);
            }
            return;
        }
        for (int i=next; i<=9; i++) {
            cur.push_back(i);
            dfs(i+1, k-1, n-i, cur, ret);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ret;
        vector<int> cur;
        
        dfs(1, k, n, cur, ret);
        return ret;
    }
};