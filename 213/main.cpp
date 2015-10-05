class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        vector<int> rob(len), robnot(len);
        
        int ret1 = nums[0];
        rob[0] = nums[0];
        for (int i=1; i<len; i++) {
            if (i == len-1) {
                continue;
            }
            rob[i] = robnot[i-1] + nums[i];
            robnot[i] = max(rob[i-1], robnot[i-1]);
            ret1 = max(ret1, rob[i]);
            ret1 = max(ret1, robnot[i]);
        }
        int ret2 = 0;
        rob[0] = robnot[0] = 0;
        for (int i=1; i<len; i++) {
            if (i == len-1) {
                ret2 = max(ret2, robnot[i-1]+nums[i]);
                continue;
            }
            rob[i] = robnot[i-1] + nums[i];
            robnot[i] = max(rob[i-1], robnot[i-1]);
            ret2 = max(ret2, rob[i]);
            ret2 = max(ret2, robnot[i]);
        }

        return max(ret1, ret2);
    }
};