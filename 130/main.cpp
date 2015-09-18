class Solution {
public:

    void bfs(vector<vector<char>>& board, int x, int y, int row, int col) {
        
        queue<pair<int, int> > que;
        que.push(make_pair(x, y));
        
        while (!que.empty()) {
            pair<int, int> pii = que.front();
            que.pop();
            
            int xx = pii.first;
            int yy = pii.second;
            
            if (xx<0 || xx>=row || yy<0 || yy>=col) continue;
            if (board[xx][yy] != 'O') continue;
            
            board[xx][yy] = '*';
            que.push(make_pair(xx-1, yy));
            que.push(make_pair(xx+1, yy));
            que.push(make_pair(xx, yy-1));
            que.push(make_pair(xx, yy+1));
        }
    }

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if (row == 0) return;
        int col = board[0].size();
        if (col == 0) return;
        
        for (int i=0; i<col; i++) {
            bfs(board, 0, i, row, col);
            bfs(board, row-1, i, row, col);
        }
        for (int i=0; i<row; i++) {
            bfs(board, i, 0, row, col);
            bfs(board, i, col-1, row, col);
        }
        
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                board[i][j] = board[i][j] == '*' ? 'O' : 'X';
            }
        }
    }
};