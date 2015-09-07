class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        
        for row in xrange(9):
            d = {}
            for col in xrange(9):
                if board[row][col] == '.': continue
                if board[row][col] in d:
                    return False
                    
                d[board[row][col]] = 1
                
        for col in xrange(9):
            d = {}
            for row in xrange(9):
                if board[row][col] == '.': continue
                if board[row][col] in d:
                    return False
                    
                d[board[row][col]] = 1
                
        for r in xrange(3):
            for c in xrange(3):
                d = {}
                for x in xrange(3):
                    for y in xrange(3):
                        row = 3 * r + x
                        col = 3 * c + y
                        if board[row][col] == '.': continue
                        if board[row][col] in d:
                            return False
                            
                        d[board[row][col]] = 1
                        
        return True
                
                