class Solution(object):

    def add(self, digits, number):
        if not digits: return [number]
        
        digits[-1] += number
        if digits[-1] >= 10:
            return self.add(digits[:-1], 1) + [digits[-1] % 10]
        return digits

    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        return self.add(digits, 1)