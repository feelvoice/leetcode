class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        
        int cur = nums[0];
        int ret = nums[0];
        for (int i=1; i<len; i++) {
            cur = cur < 0 ? nums[i] : nums[i]+cur;
            ret = max(ret, cur);
        }
        return ret;
    }
};