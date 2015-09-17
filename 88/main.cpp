class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i=m-1; i>=0; i--) {
            nums1[i+n] = nums1[i];
        }
        int cur1 = n, cur2 = 0;
        int cur = 0;
        while (1) {
            if (cur1 >= m+n) break;
            if (cur2 >= n) break;
            
            if (nums1[cur1] <= nums2[cur2]) {
                nums1[cur++] = nums1[cur1++];
            }
            else {
                nums1[cur++] = nums2[cur2++];
            }
        }
        while (cur1 < m+n) nums1[cur++] = nums1[cur1++];
        while (cur2 < n) nums1[cur++] = nums2[cur2++];
    }
};