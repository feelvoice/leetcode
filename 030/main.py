class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """  
        single_len = len(words[0])
        words_len  = len(words)
        m = {}
        for w in words:
            if w not in m:
                m[w] = 1
            else:
                m[w] += 1
        
        ret = []
        for i in xrange(len(s) - single_len*words_len + 1):
            d = {}
            flag = True
            for j in xrange(words_len):
                seg = s[i+j*single_len:i+j*single_len+single_len]
                if seg not in d:
                    d[seg] = 1
                else:
                    d[seg] += 1
                    
                if d[seg] > m.get(seg, 0):
                    flag = False
                    break
                    
            if flag:
                ret.append(i)
                
        return ret
                
                
