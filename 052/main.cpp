class Solution {
public:

    bool in(int x, int n) {
        return x>=0 && x<n;
    }

    bool is_ok(int x, int y, int n, vector<string> &board) {
        for (int i=0; i<n; i++) {
            if (board[i][y] == 'Q') return false;
            if (board[x][i] == 'Q') return false;
        }
        for (int i=-n; i<=n; i++) {
            if (in(x+i, n) && in(y+i, n) && board[x+i][y+i] == 'Q') return false;
            if (in(x-i, n) && in(y+i, n) && board[x-i][y+i] == 'Q') return false;
        }
        
        return true;
    }

    void dfs(int level, int n, vector<string> &board, int &ret) {
        if (level == n) {
            ret++;
            return;
        }
        
        for (int i=0; i<n; i++) {
            if (is_ok(level, i, n, board)) {
                board[level][i] = 'Q';
                dfs(level+1, n, board, ret);
                board[level][i] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board;
        string line(n, '.');
        for (int i=0; i<n; i++) {
            board.push_back(line);
        }

        int ret = 0;
        dfs(0, n, board, ret);
        return ret;
    }
};