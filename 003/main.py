class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        m = {}
        ans = head = 0
        for i, c in enumerate(s):
            if c in m:
                head = max(head, m[c]+1)
            ans = max(ans, i-head+1)
            m[c] = i
            
        return ans