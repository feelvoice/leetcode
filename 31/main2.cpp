#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        next_permutation(nums.begin(), nums.end());
        
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
