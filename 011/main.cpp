class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int ans = 0, cur;
        while (i < j) {
            cur = min(height[i], height[j]) * (j - i);
            ans = max(ans, cur);
            if (height[i] < height[j]) {//实力取决于短板。。。
                i++;
            }
            else {
                j--;
            }
        }
        return ans;
    }
};