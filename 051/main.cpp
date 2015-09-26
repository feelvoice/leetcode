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

    void dfs(int level, int n, vector<string> &board, vector<vector<string>> &ret) {
        if (level == n) {
            ret.push_back(board);
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

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        string line(n, '.');
        for (int i=0; i<n; i++) {
            board.push_back(line);
        }
        
        vector<vector<string>> ret;
        
        dfs(0, n, board, ret);
        return ret;
    }
};