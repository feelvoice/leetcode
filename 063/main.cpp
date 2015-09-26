class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        if (row == 0) return 0;
        int col = obstacleGrid[0].size();
        if (col == 0) return 0;
        
        vector<vector<int> > dp;
        for (int i=0; i<row; i++) {
            dp.push_back(vector<int>(col));
        }
        dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (obstacleGrid[i][j] == 0) {
                    if (i-1 >= 0) {
                        dp[i][j] += dp[i-1][j];
                    }
                    if (j-1 >= 0) {
                        dp[i][j] += dp[i][j-1];
                    }
                }
            }
        }
        return dp[row-1][col-1];
    }
};