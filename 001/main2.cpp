class Solution {
public:
    // Status: Accepted
    // Runtime: 36 ms
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int> mii;  //python dict
        
        int size = nums.size();
        for (int i=0; i<size; i++) {
            mii[nums[i]] = i;
        }
        
        for (int i=0; i<size; i++) {
            int other = target - nums[i];
            map<int, int>::iterator it = mii.find(other);
            if (it != mii.end()) {//found
                if (mii[other] > i) {// [2, 1, 3] target = 4
                    vector<int> ret;
                    ret.push_back(i + 1);
                    ret.push_back(mii[other] + 1);
                    return ret;
                }
            }
        }
    }
};