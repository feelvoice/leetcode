m = {
    '2' : "abc",
    '3' : "def",
    '4' : "ghi",
    '5' : "jkl",
    '6' : "mno",
    '7' : "pqrs",
    '8' : "tuv",
    '9' : "wxyz",
}

class Solution(object):
    def dfs(self, digits, str, ret):
        if not digits:
            ret.append(str)
            return
            
        for c in m[digits[0]]:
            self.dfs(digits[1:], str+c, ret)

    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        ret = []
        if digits:
            self.dfs(digits, "", ret)
        return ret
        
s = Solution()
print s.letterCombinations('23')
                