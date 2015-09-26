class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        for ind, n in enumerate(nums):
            d[n] = ind
            
        for ind, n in enumerate(nums):
            other = target - n
            if other in d:  #found
                if d[other] > ind:
                    ans = [ind+1, d[other]+1]
                    return ans
                
            