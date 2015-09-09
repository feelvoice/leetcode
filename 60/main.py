import math

class Solution(object):

    def get_permutation(self, n, k, arr):
        if k == 0: return ''.join(arr)
        
        prev = math.factorial(n-1)
        cur = k / prev
        return arr[cur] + self.get_permutation(n-1, k%prev, arr[0:cur] + arr[cur+1:])
        
        
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """   
        return self.get_permutation(n, k-1, [str(i+1) for i in xrange(n)])
        
        
s = Solution()
for i in xrange(6):
    print s.getPermutation(3, i+1)
    