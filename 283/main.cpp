class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]) {
                nums[left++] = nums[i];
            }
        }
        for (int i=left; i<nums.size(); i++) {
            nums[i] = 0;
        }
    }
};