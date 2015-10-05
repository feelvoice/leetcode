class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        stack<int> stk;
        int i=0, ret=0;
        while (i < height.size()) {
            if (stk.empty() || height[stk.top()] <= height[i]) {
                stk.push(i++);
            }
            else {
                int t = stk.top(); stk.pop();
                ret = max(ret, height[t]*(stk.empty() ? i : i-stk.top()-1));
            }
        }
        height.pop_back();
        return ret;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int ret = 0;
        int row = matrix.size();
        if (row == 0) return ret;
        int col = matrix[0].size();
        if (col == 0) return ret;
        
        vector<int> dp(col);
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            ret = max(ret, largestRectangleArea(dp));
        }
        return ret;
    }
};