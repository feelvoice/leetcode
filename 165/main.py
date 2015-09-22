class Solution(object):

    def trim_zero(self, v):
        while v and v[-1] == 0:
            v.pop()

    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        
        v1 = map(int, version1.split('.'))
        v2 = map(int, version2.split('.'))
        
        self.trim_zero(v1)
        self.trim_zero(v2)
        
        if v1 > v2:
            return 1
        elif v1 < v2:
            return -1
        return 0