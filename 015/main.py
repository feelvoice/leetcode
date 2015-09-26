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
            one = [k[0], k[1], -target]
            one.sort()
            ret.add(tuple(one))
            
        return ret

    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        final_ret = set()
        for i, n in enumerate(nums):
            if i and nums[i] == nums[i-1]: continue
            ret = self.twoSum(-n, nums[i+1:])
            final_ret = final_ret.union(ret)
             
        return list(final_ret)
        

s = Solution()
print s.threeSum([-1, 0, 1, 2, -1, -4])
