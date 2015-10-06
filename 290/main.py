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
        
        for i, p in enumerate(pattern):
            if p not in m:
                if str[i] in revm: return False
                m[p] = str[i]
                revm[str[i]] = p
            else:
                if m[p] != str[i]: return False
                         
        return True