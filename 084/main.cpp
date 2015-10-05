#include <iostream>
#include <vector>
#include <stack>
using namespace std;

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
        return ret;
    }
};

int main()
{
    Solution s = Solution();
    int arr[] = {2,1,5,6,2,3};
    vector<int> height(arr, arr+6);
    
    cout << s.largestRectangleArea(height) << endl;
    return 0;
}