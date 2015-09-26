class Solution(object):

    def is_valid(self, s):
        i = int(s)
        return i <= 255 and s == str(i)

    def restore(self, s, n, cur, ret):
        if n == 0:
            if not s:
                ret.append('.'.join(cur))
            return
        
        if len(s) >= 1:
            cur.append(s[0:1])
            self.restore(s[1:], n-1, cur, ret)
            cur.pop()
        
        if len(s) >= 2:
            if self.is_valid(s[0:2]):
                cur.append(s[0:2])
                self.restore(s[2:], n-1, cur, ret)
                cur.pop()
        
        if len(s) >= 3:
            if self.is_valid(s[0:3]):
                cur.append(s[0:3])
                self.restore(s[3:], n-1, cur, ret)
                cur.pop()

    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        ret = []
        cur = []
        self.restore(s, 4, cur, ret)
        return ret
        
s = Solution()
print s.restoreIpAddresses("172162541")