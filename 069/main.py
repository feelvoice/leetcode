class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        #Newton’s Iteration
        #x(n+1) = x(n) - f(x(n)) / f'(x(n))
        n = 1.0
        while abs(n * n - x) >= 1e-6:
            n = (n * n + x) / 2.0 / n
            
        return int(n)
        
        
