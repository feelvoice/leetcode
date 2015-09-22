class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = nums[0];
        int count = 1;
        for (int i=1; i<nums.size(); i++) {
            if (ret == nums[i]) {
                count++;
            }
            else {
                if (count) count--;
                else {
                    ret = nums[i];
                    count++;
                } 
            }
        }
        return ret;
    }
};