class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {  
        int row = matrix.size();
        if (row == 0) return;
        int col = matrix[0].size();
        if (col == 0) return;
        
        bool row0 = false;
        bool col0 = false;
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0 && j == 0) {
                        row0 = col0 = true;
                    }
                    else if (i == 0) {
                        row0 = true;
                    }
                    else if (j == 0) {
                        col0 = true;
                    }
                    else {
                        matrix[i][0] = matrix[0][j] = 0;
                    }
                }
            }
        }
        for (int i=1; i<row; i++) {
            if (matrix[i][0] == 0) {
                for (int j=0; j<col; j++) matrix[i][j] = 0;
            }
        }
        for (int j=1; j<col; j++) {
            if (matrix[0][j] == 0) {
                for (int i=0; i<row; i++) matrix[i][j] = 0;
            }
        }
        if (row0) {
            for (int j=0; j<col; j++) matrix[0][j] = 0;
        }
        if (col0) {
            for (int i=0; i<row; i++) matrix[i][0] = 0;
        }

    }
};