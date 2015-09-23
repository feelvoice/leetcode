class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        
        int left = 0, right = -1;
        int sum = 0;
        int ret = len+1;
        while (1) {
            while (1) {
                right++;
                if (right >= len) break;
                sum += nums[right];
                if (sum >= s) {
                    ret = min(ret, right-left+1);
                    break;
                }
            }
            while (1) {
                sum -= nums[left];
                left++;
                if (left >= len) {
                    if (ret == len+1) return 0;
                    return ret;
                }
                if (sum >= s) {
                    ret = min(ret, right-left+1);
                }
                else {
                    break;
                }
            }
        }
    }
};