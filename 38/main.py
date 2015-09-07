class Solution(object):

    def trans(self, s):
        ret = ''
        cur_ch = s[0]
        cur_len = 1
        for c in s[1:]:
            if c == cur_ch:
                cur_len += 1
            else:
                ret += "%d%s" % (cur_len, cur_ch)
                cur_ch = c
                cur_len = 1
                
        ret += "%d%s" % (cur_len, cur_ch)
        return ret
            

    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        s = '1'
        for i in xrange(n-1):
            s = self.trans(s)
            
        return s
        
   
#s = Solution()
#s.countAndSay(5)