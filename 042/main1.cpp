class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        int sec_height = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                sec_height = max(height[left], sec_height);
                ans += sec_height - height[left];
                left++;
            }
            else {
                sec_height = max(height[right], sec_height);
                ans += sec_height - height[right];
                right--;
            }
        }
        
        return ans;
    }
};