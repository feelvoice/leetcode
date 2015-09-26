class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int len = nums.size();
        int i = 0;
        while (i < len) {
            if (nums[i] > 0 && nums[i] <= len && nums[i] != i+1 && nums[nums[i]-1] != nums[i]) {
                swap(nums[i], nums[nums[i]-1]);
            }
            else {
                i++;
            }
        }
        
        for (int i=0; i<len; i++) {
            if (nums[i] != i+1) return i+1;
        }
        return len+1;
    }
};