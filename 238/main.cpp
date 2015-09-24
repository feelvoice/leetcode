class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret(len, 1);
        
        for (int i=len-1; i>=0; i--) {
            ret[i] = (i==len-1) ? 1 : ret[i+1] * nums[i+1];
        }
        int tot = 1;
        for (int i=0; i<len; i++) {
            ret[i] *= tot;
            tot *= nums[i];
        }
        return ret;
    }
};