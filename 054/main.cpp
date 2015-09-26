#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ret;
        int row = matrix.size();
        if (row == 0) return ret;
        int col = matrix[0].size();
        if (col == 0) return ret;
        
        int up = 1, down = row-1, left = 0, right = col-1;
        int i = 0, j = 0;
        while (1) {
            if (j > right) break;
            while (j <= right) {
                ret.push_back(matrix[i][j]);
                j++;
            }
            j--; i++;
            right--;
            if (i > down) break;
            while (i <= down) {
                ret.push_back(matrix[i][j]);
                i++;
            }
            i--; j--;
            down--;
            if (j < left) break;
            while (j >= left) {
                ret.push_back(matrix[i][j]);
                j--;
            }
            j++; i--;
            left++;
            if (i < up) break;
            while (i >= up) {
                ret.push_back(matrix[i][j]);
                i--;
            }
            i++; j++;
            up++;
        }
        
        return ret;
    }
};

int main()
{
    Solution s = Solution();
    vector<vector<int> > matrix;
    
    vector<int> row(4);
    row[0] = 1; row[1] = 2; row[2] = 3; row[3] = 4; matrix.push_back(row);
    row[0] = 5; row[1] = 6; row[2] = 7; row[3] = 8; matrix.push_back(row);
    row[0] = 9; row[1] = 10; row[2] = 11; row[3] = 12; matrix.push_back(row);
    row[0] = 13; row[1] = 14; row[2] = 15; row[3] = 16; matrix.push_back(row);
    
    vector<int> ret = s.spiralOrder(matrix);
    for (int i=0; i<ret.size(); i++) {
        cout << ret[i] << ' ';
    }
    cout << endl;
}