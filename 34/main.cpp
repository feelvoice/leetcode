class Solution {
public:

    int left_range_search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        int ret = -1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                ret = mid;
                right = mid - 1;
            }
        }
        return ret;
    }
    
    int right_range_search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        int ret = -1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                ret = mid;
                left = mid + 1;
            }
        }
        return ret;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        
        int idx = left_range_search(nums, target);
        ret.push_back(idx);
        ret.push_back(idx);
        if (idx == -1) {
            return ret;
        }
        ret[1] = right_range_search(nums, target);
        return ret;
    }
};