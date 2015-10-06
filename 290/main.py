class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        pattern = [c for c in pattern]
        str = str.split()        
        if len(pattern) != len(str): return False
        
        m = {}
        revm = {}
        
        for s, p in zip(str, pattern):
            if p not in m:
                if s in revm: return False
                m[p] = s
                revm[s] = p
            else:
                if m[p] != s: return False
                         
        return True