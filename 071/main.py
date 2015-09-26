class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        ret = []
        path = path.split('/')
        for p in path:
            if not p or p == '.': 
                continue
            elif p == '..':
                if ret: ret.pop()
            else:
                ret.append(p)
                
        return '/' + '/'.join(ret)
                