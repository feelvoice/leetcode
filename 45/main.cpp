class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0;
        int curMax = 0, curRch = 0;
        for (int i=0; i<nums.size(); i++) {
            if (curRch < i) {
                ret++;
                curRch = curMax;
            }
            curMax = max(curMax, nums[i]+i);
        }
        
        return ret;
    }
};