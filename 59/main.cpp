#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ret;
        vector<int> row(n);
        for (int i=0; i<n; i++) {
            ret.push_back(row);
        }
        
        int up = 1, down = n-1, left = 0, right = n-1;
        int i = 0, j = 0;
        int cur = 1;
        while (1) {
            if (j > right) break;
            while (j <= right) {
                ret[i][j] = cur++;
                j++;
            }
            j--; i++;
            right--;
            if (i > down) break;
            while (i <= down) {
                ret[i][j] = cur++;
                i++;
            }
            i--; j--;
            down--;
            if (j < left) break;
            while (j >= left) {
                ret[i][j] = cur++;
                j--;
            }
            j++; i--;
            left++;
            if (i < up) break;
            while (i >= up) {
                ret[i][j] = cur++;
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
    vector<vector<int> > ret = s.generateMatrix(3);
    for (int i=0; i<ret.size(); i++) {
        for (int j=0; j<ret[i].size(); j++) {
            cout << ret[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}