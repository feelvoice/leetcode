class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        slen = len(s)
        group = 2 * numRows - 2 if numRows != 1 else 1
        ret = []
        for r in xrange(numRows):
            cur = r
            gsum = group
            while cur < slen:
                ret.append(s[cur])
                other = gsum - cur
                if r!=0 and r!=numRows-1 and other<slen:
                    ret.append(s[other])

                cur += group
                gsum += 2 * group

        return ''.join(ret)
