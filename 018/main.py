class Solution(object):  
    def twoSum(self, target, nums):
        d = {}
        
        nlen = len(nums)
        i, j = 0, nlen-1
        while i < j:
            tsum = nums[i] + nums[j]
            if tsum == target:
                one = (nums[i], nums[j])
                d[one] = 1
                i += 1
                j -= 1     
            elif tsum > target:
                j -= 1
            else:
                i += 1
                
        ret = set()
        for k in d:
            ret.add(k)
            
        return ret

    def threeSum(self, target, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ret = set()
        final_ret = set()
        for i, n in enumerate(nums):
            if i and nums[i] == nums[i-1]: continue
            one = self.twoSum(target-n, nums[i+1:])
            for t in one:   
                final_ret.add(tuple(sorted(list(t) + [n])))
        
        return final_ret
        
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        final_ret = set()
        for i, n in enumerate(nums):
            if i and nums[i] == nums[i-1]: continue
            one = self.threeSum(target-n, nums[i+1:])
            for t in one:   
                final_ret.add(tuple(sorted(list(t) + [n])))
             
        return list(final_ret)
        

s = Solution()
print s.fourSum([1, 0, -1, 0, -2, 2], 0)