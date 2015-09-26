#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        
        int ret = 1, cur = 1;
        bool dup = false;
        for (int i=1; i<len; i++) {
            if (nums[i] != nums[cur-1]) {
                swap(nums[i], nums[cur]);
                cur++;
                ret++;
                dup = false;
            }
            else if (!dup) {
                swap(nums[i], nums[cur]);
                cur++;
                ret++;
                dup = true;
            }
        }
        return ret;
    }
};

int main()
{
    Solution s = Solution();
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    cout << s.removeDuplicates(nums) << endl;
    for (int i=0; i<nums.size(); i++) {
        cout << nums[i] << ' ';
    }
    cout << endl;
    return 0;
}