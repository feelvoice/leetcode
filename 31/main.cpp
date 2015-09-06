#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

class Solution {
public:
    void my_reverse(vector<int>& nums, int start, int end) {
        for (int i=start, j=end-1; i<j; i++,j--) {
            swap(nums[i], nums[j]);
        }
    }

    void nextPermutation(vector<int>& nums) {
        int len = nums.size(), i, j;
        if (len <= 1) return;
        
        for (i=len-1; i>=1; i--) {
            if (nums[i] > nums[i-1]) break;
        }
        if (i == 0) {
            my_reverse(nums, 0, len);
            return;
        }
        
        for (j=len-1; j>=i; j--) {
            if (nums[j] > nums[i-1]) break;
        }
        swap(nums[i-1], nums[j]);
        my_reverse(nums, i, len);
    }
};

int main() {
    Solution s = Solution();
    vector<int> vi;
    vi.push_back(1);
    vi.push_back(2);
    s.nextPermutation(vi);
    for (int i=0; i<vi.size(); i++) {
        printf("%d ", vi[i]);
    }
    printf("\n");
    
    return 0;
}