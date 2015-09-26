class Solution(object):

    def dfs(self, level, row, cur, ret, d):
        if level == len(row):
            ret.append(cur[:])
            return
            
        for i in xrange(d[row[level]]+1):
            cur.extend([row[level]] * i)
            self.dfs(level+1, row, cur, ret, d)
            for j in xrange(i): cur.pop()
        

    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        d = {}
        for n in nums:
            d[n] = d.get(n, 0) + 1
            
        row = sorted(d.keys())
        
        ret = []
        cur = []
        self.dfs(0, row, cur, ret, d)
        return ret
        
        
s = Solution()
print s.subsets([1,2,3])