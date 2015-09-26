class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not str: return ''
        cur = 0
        while True:
            d = {}
            for s in strs:
                if cur >= len(s):
                    return s[0:cur]
                    
                d[s[cur]] = 1
                if len(d) > 1:
                    return s[0:cur]
                    
            cur += 1
                    
                  
s = Solution()
print s.longestCommonPrefix(['aaa'])
                    
                