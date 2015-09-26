#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int find_min_index(vector<int>& nums, int left, int right) {
        if (left > right) return -1;
        
        int mid = (left + right) / 2;
        if (nums[left] <= nums[mid]) {
            int r_min_index = find_min_index(nums, mid+1, right);
            if (r_min_index == -1) return left;
            return nums[left] < nums[r_min_index] ? left : r_min_index;
        }
        else {
            int r_min_index = mid + 1 <= right ? mid + 1 : -1;
            int l_min_index = find_min_index(nums, left, mid);
            if (r_min_index == -1) return l_min_index;
            else if (l_min_index == -1) return r_min_index;
            return nums[l_min_index] < nums[r_min_index] ? l_min_index : r_min_index;
        }
    }
    
    int my_binary_search(vector<int> &nums, int left, int right, int target) {
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pos = find_min_index(nums, 0, nums.size()-1);
        
        int idx = my_binary_search(nums, 0, pos-1, target);
        if (idx != -1) return idx;
        return my_binary_search(nums, pos, nums.size()-1, target);
    }
};

int main()
{
    Solution s = Solution();
    vector<int> vi;
    vi.push_back(5);
    vi.push_back(1);
    vi.push_back(3);
    
    cout << s.search(vi, 1) << endl;
    return 0;
}