#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    void dfs(int level, vector<int> &nums, vector<int> &cur, vector<vector<int> > &ret) {
        if (level == nums.size()) {
            ret.push_back(cur);
            return;
        }
        
        for (int i=level; i<nums.size(); i++) {
            swap(nums[level], nums[i]);
            cur.push_back(nums[level]);
            dfs(level+1, nums, cur, ret);
            cur.pop_back();
            swap(nums[level], nums[i]);
        }
    }

    vector<vector<int> > permute(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int> > ret;
        dfs(0, nums, cur, ret);
        return ret;
    }
};

int main()
{
    Solution s = Solution();
    vector<int> vi;
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(3);
    s.permute(vi);
    return 0;
}