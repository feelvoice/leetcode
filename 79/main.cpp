class Solution {
public:

    bool dfs(int x, int y, int cur, string word, vector<vector<char>>& board, int row, int col) {
        if (cur == word.length()) return true;
        if (x<0 || x>=row || y<0 || y>=col || board[x][y] != word[cur]) return false;
        
        char tmp = board[x][y];
        board[x][y] = '\0';
        if (dfs(x+1, y, cur+1, word, board, row, col)) return true;
        if (dfs(x-1, y, cur+1, word, board, row, col)) return true;
        if (dfs(x, y+1, cur+1, word, board, row, col)) return true;
        if (dfs(x, y-1, cur+1, word, board, row, col)) return true;
        board[x][y] = tmp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        if (row == 0) return false;
        int col = board[0].size();
        if (col == 0) return false;
        
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (dfs(i, j, 0, word, board, row, col)) {
                    return true;
                }
            }
        }
        return false;
    }
};