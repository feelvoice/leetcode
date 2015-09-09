class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        int row_lim = n / 2;
        double center_x = (n - 1) / 2.0;
        double center_y = (n - 1) / 2.0;
        double offset_x, offset_y;
        
        for (int i=0; i<row_lim; i++) {
            int col_lim = n - 1 - i;
            for (int j=i; j<col_lim; j++) {
                offset_x = i - center_x;
                offset_y = j - center_y;
                
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[center_x - offset_y][center_y + offset_x];
                matrix[center_x - offset_y][center_y + offset_x] = matrix[center_x - offset_x][center_y - offset_y];
                matrix[center_x - offset_x][center_y - offset_y] = matrix[center_x + offset_y][center_y - offset_x];
                matrix[center_x + offset_y][center_y - offset_x] = tmp;
            }
        }
    }
};