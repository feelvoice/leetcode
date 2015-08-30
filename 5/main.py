class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        T = '^' + '#'.join([''] + [c for c in s] + ['']) + '$' #whatever two diffrent marks
        R = 0 #right bound
        C = 0 #center
        n = len(T)        
        P = [0] * n

        maxp = 0
        maxi = 0
        for i in xrange(1, n-1):
            mirror = C - (i - C)
            if R > i:
                P[i] = min(R-i, P[mirror]) 

            while T[i-1-P[i]] == T[i+1+P[i]]:
                P[i] += 1

            if P[i] > maxp:
                maxp = P[i]
                maxi = i

            if i + P[i] > R:
                C = i
                R = i + P[i]

        start = (maxi - 1 - maxp) / 2
        return s[start:start+maxp]

