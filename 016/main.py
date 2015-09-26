INT_MAX = 2 ** 31

class Solution(object):
    def twoSumClosest(self, nums, target):
        i, j = 0, len(nums)-1
        diff = INT_MAX

        while i < j:
            tsum = nums[i] + nums[j]
            if tsum == target:
                return 0
            elif tsum > target:
                j -= 1
            else:
                i += 1
                
            newdiff = tsum - target
            if abs(newdiff) < abs(diff):
                diff = newdiff
                
        return diff

    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        diff = INT_MAX
        for i, n in enumerate(nums):
            if i and nums[i] == nums[i-1]: continue
            newdiff = self.twoSumClosest(nums[i+1:], target-n)
            if abs(newdiff) < abs(diff):
                diff = newdiff
                
        return target + diff



s = Solution()
print s.threeSumClosest([-4, -1, 1, 2], 1)
