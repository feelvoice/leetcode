class Solution(object):
    
    def fib(self, n, d):
        if n == 0:
            return 1
        elif n == 1:
            return 1
        
        if n in d:
            return d[n]
           
        d[n] = self.fib(n-1, d) + self.fib(n-2, d)
        return d[n]
          

    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        d = {}
        return self.fib(n, d)
            