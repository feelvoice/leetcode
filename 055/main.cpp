class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int max_pos = 0;
        for (int i=0; i<nums.size(); i++) {
            if (i > max_pos) return false;
            max_pos = max(max_pos, nums[i]+i);
        }
        return true;
    }
};