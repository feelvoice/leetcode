class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len <= 2) return 0;
        
        int maxh = -1, maxi;
        for (int i=0; i<len; i++) {
            if (height[i] > maxh) {
                maxh = height[i];
                maxi = i;
            }
        }
        
        int ans = 0;
        int edge = height[0];
        for (int i=1; i<maxi; i++) {
            if (edge < height[i]) edge = height[i];
            else ans += edge - height[i];
        }
        edge = height[len-1];
        for (int i=len-2; i>maxi; i--) {
            if (edge < height[i]) edge = height[i];
            else ans += edge - height[i];
        }
        return ans;
    }
};