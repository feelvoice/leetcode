class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (nums[i] == n || nums[i] == i) continue;
            swap(nums[i], nums[nums[i]]);
            i--;
        }
        for (int i=0; i<n; i++) {
            if (nums[i] == n) return i;
        }
        return n;
    }
};