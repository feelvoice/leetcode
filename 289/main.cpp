class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        if (row == 0) return;
        int col = board[0].size();
        if (col == 0) return;
        
        int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int count, x, y;
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                count = 0;
                for (int k=0; k<8; k++) {
                    x = i + dx[k];
                    y = j + dy[k];
                    if (x<0 || x>=row || y<0 || y>=col) continue;
                    if (board[x][y] == 1 || board[x][y] == 2) count++;
                }
                if (board[i][j] == 1) {
                    if (count < 2) board[i][j] = 2;
                    else if (count > 3) board[i][j] = 2;
                }
                else {
                    if (count == 3) board[i][j] = 3;
                }
            }
        }
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                board[i][j] %= 2;
            }
        }
    }
};