class Solution {
public:
    
    // Time Limit Exceeded
    // O(n^2)
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int size = nums.size();
        for (int i=0; i<size; i++) {
            for (int j=i+1; j<size; j++) {
                if (nums[i] + nums[j] == target) {
                    vector<int> ret;
                    ret.push_back(i+1); //1-based
                    ret.push_back(j+1);
                    return ret;
                }
            }
        }
        
    }
};