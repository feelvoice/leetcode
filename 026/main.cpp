class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int prev = 0;
        for (int i=1; i<n; i++) {
            if (nums[i] == nums[prev]) continue;
            nums[prev+1] = nums[i];
            prev++;
        }
        return prev+1;
    }
};