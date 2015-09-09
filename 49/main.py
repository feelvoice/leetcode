class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        
        d = {}
        for s in strs:
            key = tuple(sorted(s))
            if key not in d:
                d[key] = []
                
            d[key].append(s)
            
        return [sorted(l) for l in d.values()]