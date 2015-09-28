class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        if (row == 0) return 0;
        int col = dungeon[0].size();
        if (col == 0) return 0;
        
        vector<vector<int> > dp(row, vector<int>(col));
        dp[row-1][col-1] = max(1 - dungeon[row-1][col-1], 1);
        for (int i=row-2; i>=0; i--) {
            dp[i][col-1] = max(dp[i+1][col-1] - dungeon[i][col-1], 1);
        }
        for (int j=col-2; j>=0; j--) {
            dp[row-1][j] = max(dp[row-1][j+1] - dungeon[row-1][j], 1);
        }
        for (int i=row-2; i>=0; i--) {
            for (int j=col-2; j>=0; j--) {
                dp[i][j] = min(max(dp[i+1][j]-dungeon[i][j], 1), max(dp[i][j+1]-dungeon[i][j], 1));
            }
        }
        return dp[0][0];
    }
};