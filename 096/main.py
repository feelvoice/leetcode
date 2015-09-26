class Solution(object):
    def num(self, n, d):
        if n <= 1: return 1
        if n in d:
            return d[n]
            
        ret = 0
        for i in xrange(n):
            ret += self.num(i, d) * self.num(n-1-i, d)
            
        d[n] = ret
        return ret

    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        d = {}
        return self.num(n, d)