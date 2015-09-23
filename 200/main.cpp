class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& grid, int row, int col) {
        if (i<0 || i>=row || j<0 || j>=col || grid[i][j] != '1') return;
        grid[i][j] = '0';
        dfs(i+1, j, grid, row, col);
        dfs(i-1, j, grid, row, col);
        dfs(i, j+1, grid, row, col);
        dfs(i, j-1, grid, row, col);
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        if (col == 0) return 0;
        
        int ret = 0;
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid, row, col);
                    ret++;
                }
            }
        }
        return ret;
    }
};