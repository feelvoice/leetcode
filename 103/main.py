# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import Queue
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ret = []
        if not root: return ret
        
        que = Queue.Queue()
        que.put(root)
        que.put(None)
        
        level = []
        while not que.empty():
            cur = que.get()
            if cur is None:
                ret.append(level)
                level = []
                if not que.empty():
                    que.put(None)
            else:
                level.append(cur.val)
                if cur.left:  que.put(cur.left)
                if cur.right: que.put(cur.right)
                
        return ret

    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ret = self.levelOrder(root)
        for i in xrange(1, len(ret), 2):
            ret[i].reverse()
            
        return ret
    