class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        for (int i=0; i<len; i++) {
            if (nums[0] == nums[nums[0]]) return nums[0];
            swap(nums[0], nums[nums[0]]);
            i--;
        }
        return nums[0];
    }
};