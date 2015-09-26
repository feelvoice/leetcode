def C(m, n):
    return math.factorial(n) / math.factorial(m) / math.factorial(n-m)

class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        return C(m-1, m+n-2)