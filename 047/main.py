class Solution(object):

    def dfs(self, arr, d, cur, ret):
    
        done = True
        for n in arr:
            if d[n] > 0:
                done = False
                cur.append(n)
                d[n] -= 1
                self.dfs(arr, d, cur, ret)
                d[n] += 1
                cur.pop()
                
        if done:
            ret.append(cur[:])


    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        d = {}
        for n in nums:
            d[n] = d.get(n, 0) + 1
            
        arr = sorted(d.keys())
            
        ret = []
        cur = []
        self.dfs(arr, d, cur, ret)
        return ret
        
s = Solution()
print s.permuteUnique([1,1,2])