class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x_or = 0;
        for (int i=0; i<nums.size(); i++) {
            x_or ^= nums[i];
        }
        
        int lowbit =  x_or & -x_or; //...
        int a = 0, b = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] & lowbit) {
                a ^= nums[i];
            }
            else {
                b ^= nums[i];
            }
        }
        vector<int> ret;
        ret.push_back(a);
        ret.push_back(b);
        return ret;
    }
};