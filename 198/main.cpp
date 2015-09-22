class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        vector<int> rob(len), robnot(len);
        
        int ret = nums[0];
        rob[0] = nums[0];
        for (int i=1; i<len; i++) {
            rob[i] = robnot[i-1] + nums[i];
            robnot[i] = max(rob[i-1], robnot[i-1]);
            ret = max(ret, rob[i]);
            ret = max(ret, robnot[i]);
        }
        return ret;
    }
};