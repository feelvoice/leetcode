class Solution(object):

    def format_line(self, words, maxWidth, is_last):
        if len(words) == 1:
            return words[0] + ' ' * (maxWidth - len(words[0]))
            
        if is_last: 
            ret = ' '.join(words)
            if len(ret) < maxWidth:
                ret += ' ' * (maxWidth - len(ret))    
            return ret
            
            
        total_len = sum(map(len, words))
        space = (maxWidth - total_len) / (len(words) - 1)
        left = maxWidth - total_len - space * (len(words) - 1)
        
        ret = words[0]
        for s in words[1:]:
            ret += ' ' * space
            if left:
                ret += ' '
                left -= 1
            ret += s
            
        return ret
                
    def gao(self, words, maxWidth, ret):
        if not words: return
        
        curlen = len(words[0])
        curi = 1
        is_last = False
        for i, s in enumerate(words[1:]):
            curi = i + 1
            curlen += len(s) + 1
            if curlen > maxWidth: break
        else:
            curi = len(words)
            is_last = True
            
        line = self.format_line(words[:curi], maxWidth, is_last)
        ret.append(line)
        self.gao(words[curi:], maxWidth, ret)

    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        ret = []
        self.gao(words, maxWidth, ret)
        return ret
        
        
        
s = Solution()
print s.fullJustify(["What","must","be","shall","be."], 12)