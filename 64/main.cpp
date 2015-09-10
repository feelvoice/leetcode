class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        if (col == 0) return 0;
        
        vector<vector<int> > dp(row, vector<int>(col));
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                dp[i][j] = grid[i][j];
                if (i-1 >= 0 && j-1 >= 0) {
                    dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
                }
                else if (i-1 >= 0) {
                    dp[i][j] += dp[i-1][j];
                }
                else if (j-1 >= 0) {
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[row-1][col-1];
    }
};