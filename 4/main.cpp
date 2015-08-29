double find_kth(vector<int>& nums1, vector<int>& nums2, int s1, int len1, int s2, int len2, int k) {
    if (len1 > len2) {
        return find_kth(nums2, nums1, s2, len2, s1, len1, k);
    }
    
    if (len1 == 0) {
        return nums2[s2+k-1];
    }
    else if (k == 1) {
        return min(nums1[s1], nums2[s2]);
    }
    
    int pa = min(k/2, len1), pb = k - pa;
    if (nums1[s1+pa-1] > nums2[s2+pb-1]) {
        return find_kth(nums1, nums2, s1, len1, s2+pb, len2-pb, k-pb);
    }
    else if (nums1[s1+pa-1] < nums2[s2+pb-1]) {
        return find_kth(nums1, nums2, s1+pa, len1-pa, s2, len2, k-pa);
    }
    else {
        return nums1[s1+pa-1];
    }
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int total = n1 + n2;
        
        if (total & 1) {//odd
            return find_kth(nums1, nums2, 0, n1, 0, n2, total/2+1);
        }
        else {
            return (find_kth(nums1, nums2, 0, n1, 0, n2, total/2) +
                find_kth(nums1, nums2, 0, n1, 0, n2, total/2+1)) / 2.0;
        }
    }
};