class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0) return false;
        int col = matrix[0].size();
        if (col == 0) return false;
        
        int i = 0, j = row - 1, mid;
        while (i <= j) {
            mid = (i + j) / 2;
            if (matrix[mid][0] > target) j--;
            else i++;
        }
        if (j == -1) return false;
        int cur = j;
        i = 0, j = col - 1;
        while (i <= j) {
            mid = (i + j) / 2;
            if (matrix[cur][mid] == target) return true;
            else if (matrix[cur][mid] > target) j--;
            else i++;
        }
        return false;
    }
};