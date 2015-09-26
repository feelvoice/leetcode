class Solution(object):

    def dfs(self, candidates, target, cur, ret, d):
        if target == 0:
            ret.append(cur[:])
            return

        if not candidates: return
        if candidates[0] > target: return
        
        lim = min(target / candidates[0], d[candidates[0]])
        for i in xrange(lim+1):
            cur.extend([candidates[0]] * i)
            self.dfs(candidates[1:], target-i*candidates[0], cur, ret, d)
            for j in xrange(i):
                cur.pop()
            
        
        
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ret = []
        d = {}
        for c in candidates:
            d[c] = d.get(c, 0) + 1
            
        candidates = sorted(d.keys())
        cur = []
        self.dfs(candidates, target, cur, ret, d)
        return ret
        
        
        
s = Solution()
print s.combinationSum2([10,1,2,7,6,1,5], 8)
        