class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return false;
        int i=0, j=len-1, mid;
        while (i <= j) {
            mid = (i + j) / 2;
            if (nums[mid] == target) return true;
            
            if (nums[i] < nums[mid]) {
                if (target >= nums[i] && target < nums[mid]) {
                    j = mid - 1;
                }
                else {
                    i = mid + 1;
                }
            }
            else if (nums[i] > nums[mid]) {
                if (target > nums[mid] && target <= nums[j]) {
                    i = mid + 1;
                }
                else {
                    j = mid - 1;
                }
            }
            else {
                i++;
            }
        }
        return false;
    }
};