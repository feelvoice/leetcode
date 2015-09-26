class Solution(object):

    def dfs(self, candidates, target, cur, ret):
        if target == 0:
            ret.append(cur[:])
            return
    
        if not candidates: return
            
        self.dfs(candidates[1:], target, cur, ret)
        if candidates[0] <= target:
            cur.append(candidates[0])
            self.dfs(candidates, target-candidates[0], cur, ret)
            cur.pop()
        
        

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ret = []
        candidates.sort()
        
        cur = []
        self.dfs(candidates, target, cur, ret)
        return ret
            
            
s = Solution()
print s.combinationSum([7,6,3,2], 7)
