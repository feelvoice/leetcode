class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        ret = []
        while True:
            n -= 1
            ret.append(chr(ord('A') + n % 26))
            n /= 26
            if not n: break
            
        return ''.join(ret[::-1])
            