class Solution {
public:
    bool flag;
    
    bool is_ladder(const string &a, const string &b) {
        int ret = 0;
        for (int i=0; i<a.length(); i++) {
            if (a[i] != b[i]) ret++; 
        }
        return ret == 1;
    }
    
    void bfs(int &ret, int cur, int next, vector<string> rot[], const string &goal, unordered_set<string>& wordList) {
        if (flag) return;
        
        int len = rot[cur].size();
        rot[next].clear();
        for (int i=0; i<len; i++) {
            if (is_ladder(rot[cur][i], goal)) {
                flag = true;
                return;
            }
            for (unordered_set<string>::iterator it=wordList.begin(); it!=wordList.end();) {
                if (is_ladder(rot[cur][i], *it)) {
                    rot[next].push_back(*it);
                    it = wordList.erase(it);
                }
                else {
                    ++it;
                }
            }
        }
        if (rot[next].size() == 0) {
            ret = 0;
            flag = true;
            return;
        }
        ret++;
        bfs(ret, next, cur, rot, goal, wordList);
    }

    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        vector<string> rot[2];
        int cur = 0, next = 1;
        rot[cur].push_back(endWord);
        
        int ret = 2;
        flag = false;
        bfs(ret, cur, next, rot, beginWord, wordList);
        return ret;
    }
};