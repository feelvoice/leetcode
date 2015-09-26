class Solution {
public:

    int max_sum_arr(vector<int>& nums, int start, int end) {
        if (start == end) {
            return nums[start];
        }
        
        int mid = start + (end - start) / 2;
        int ret = max(max_sum_arr(nums, start, mid), 
            max_sum_arr(nums, mid+1, end));
        
        int max1 = nums[mid];
        int cur1 = nums[mid];
        for (int i=mid-1; i>=start; i--) {
            cur1 += nums[i];
            max1 = max(max1, cur1);
        }
        
        int max2 = nums[mid+1];
        int cur2 = nums[mid+1];
        for (int i=mid+2; i<=end; i++) {
            cur2 += nums[i];
            max2 = max(max2, cur2);
        }
        ret = max(ret, max1+max2);
        return ret;
    }

    int maxSubArray(vector<int>& nums) {
        return max_sum_arr(nums, 0, nums.size()-1);
    }
};