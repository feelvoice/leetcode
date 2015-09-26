class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        strs = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        
        ret = 0
        for i, c in enumerate(strs):
            while s.startswith(c):
                ret += values[i]
                s = s.split(c, 1)[1]
                
        return ret
        
'''        
s = Solution()
print s.romanToInt('MCMLXXX')
'''
            
        
