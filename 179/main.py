class Solution(object):

    def compare(self, x, y):
        x, y = x+y, y+x
        return cmp(x, y)

    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        nums = sorted(map(str, nums), cmp=lambda x, y:self.compare(x, y), reverse=True)
        nums = ''.join(nums)
        return str(int(nums))
        
'''       
s = Solution()
print s.largestNumber([3, 30, 34, 5, 9])
'''