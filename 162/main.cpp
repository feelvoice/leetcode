class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid;
        while (left <= right) {
            if (left == right) return left;
            
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid+1]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
    }
};