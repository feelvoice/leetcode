#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    void dfs(int level, int left, int n, vector<int> &row, vector<int> &cur, vector<vector<int> > &ret) {
        if (left == 0) {
            ret.push_back(cur);
            return;
        }
        
        for (int i=level; i<=n-left; i++) {
            cur.push_back(row[i]);
            dfs(i+1, left-1, n, row, cur, ret);
            cur.pop_back();
        }
    }

    vector<vector<int> > combine(int n, int k) {
        vector<int> cur, row;
        vector<vector<int> > ret;
        for (int i=1; i<=n; i++) {
            row.push_back(i);
        }
        
        dfs(0, k, n, row, cur, ret);
        return ret;
    }
};

int main()
{
    Solution s = Solution();
    vector<vector<int> > ret = s.combine(4, 2);
    for (int i=0; i<ret.size(); i++) {
        for (int j=0; j<ret[i].size(); j++) {
            cout << ret[i][j] << ' ';
        }
        cout << endl;
    }
    
    return 0;
}

