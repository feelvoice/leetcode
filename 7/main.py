class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        INT_MAX = 2 ** 31 - 1
        INT_MIN = -1 - INT_MAX
        
        sign = 1 if x >= 0 else -1
        xx = x if x >= 0 else -x
        
        ret = 0
        while xx:
            ret = ret * 10 + xx % 10
            xx /= 10
            
        ret *= sign
        if ret > INT_MAX or ret < INT_MIN:
            return 0
        return ret