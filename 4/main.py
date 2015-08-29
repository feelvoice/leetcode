class Solution(object):

    def find_kth(self, nums1, nums2, k):
        len1 = len(nums1)
        len2 = len(nums2)
        
        if len1 > len2:
            return self.find_kth(nums2, nums1, k)
        
        if len1 == 0:
            return nums2[k-1]
        elif k == 1:
            return min(nums1[0], nums2[0])
        
        pa = min(k/2, len1)
        pb = k - pa
        if nums1[pa-1] < nums2[pb-1]:
            return self.find_kth(nums1[pa:], nums2, k-pa)
        elif nums1[pa-1] > nums2[pb-1]:
            return self.find_kth(nums1, nums2[pb:], k-pb)
        else:
            return nums1[pa-1]
        

    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        total_len = len(nums1) + len(nums2)
        if total_len & 1:#odd
            return self.find_kth(nums1, nums2, total_len/2+1)
        else:
            return (self.find_kth(nums1, nums2, total_len/2) + 
                self.find_kth(nums1, nums2, total_len/2+1)) / 2.0
        
        
        
        