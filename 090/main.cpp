class Solution {
public:
    void dfs(int level, int n, vector<int> &key, vector<int> &cur, vector<vector<int> > &ret, map<int, int> &d) {
        if (level == n) {
            ret.push_back(cur);
            return;
        }
        
        for (int i=0; i<=d[key[level]]; i++) {
            for (int j=0; j<i; j++) cur.push_back(key[level]);
            dfs(level+1, n, key, cur, ret, d);
            for (int j=0; j<i; j++) cur.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int, int> d;
        for (int i=0; i<nums.size(); i++) {
            d[nums[i]]++;
        }
        
        vector<int> key;
        for (map<int, int>::iterator i=d.begin(); i!=d.end(); ++i) {
            key.push_back(i->first);
        }
        
        vector<int> cur;
        vector<vector<int> > ret;
        dfs(0, key.size(), key, cur, ret, d);
        return ret;
    }
};