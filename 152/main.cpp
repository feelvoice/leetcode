#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        int ret = nums[0];
        int prevpos = nums[0] > 0 ? nums[0] : -1;
        int prevneg = nums[0] < 0 ? nums[0] : 1;
        int newpos, newneg;
        for (int i=1; i<len; i++) {
            ret = max(ret, nums[i]);
            if (nums[i] > 0) {
                newpos = max(nums[i], prevpos*nums[i]);
                if (prevneg < 0) newneg = prevneg*nums[i];
                else newneg = 1;
            }
            else if (nums[i] < 0) {
                newneg = min(nums[i], prevpos*nums[i]);
                if (prevneg < 0) newpos = prevneg*nums[i];
                else newpos = -1;
            }
            else {
                newpos = newneg = 0;
            }

            ret = max(ret, newpos);
            prevpos = newpos;
            prevneg = newneg;
        }
        
        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<int> vi;
    vi.push_back(2);
    vi.push_back(-5);
    vi.push_back(-2);
    vi.push_back(-4);
    vi.push_back(3);
    cout << s.maxProduct(vi) << endl;
}