# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if not intervals: return []
        intervals = sorted(intervals, key=lambda x:(x.start, x.end))
        
        ret = []
        cur = intervals[0]
        for i in intervals[1:]:
            if i.start <= cur.end:
                cur.end = max(cur.end, i.end)
            else:
                ret.append(cur)
                cur = i
        
        ret.append(cur)
        return ret