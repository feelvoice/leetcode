class Solution(object):

    def count_r20(self, board, i, j):
        r20 = set()
        for row in xrange(9):
            if board[row][j] != '.':
                r20.add(board[row][j])
                
        for col in xrange(9):
            if board[i][col] != '.':
                r20.add(board[i][col])
                
        r = i / 3 * 3
        c = j / 3 * 3
        for x in xrange(3):
            for y in xrange(3):
                if board[r+x][c+y] != '.':
                    r20.add(board[r+x][c+y])
                    
        all = set([str(x+1) for x in xrange(9)])
        remain = all - r20 
        return remain
        

    def dfs(self, board, valid):
        if valid == 81: return True
    
        possibility = 10 #large than 9~
        min_r = set()
        for i in xrange(9):
            for j in xrange(9):
                if board[i][j] != '.': continue
                r = self.count_r20(board, i, j)
                len_r = len(r)
                if len_r and len_r < possibility:
                    possibility = len_r
                    min_r = r
                    min_i = i 
                    min_j = j
            
        for digit in min_r:
            board[min_i][min_j] = str(digit)
            if self.dfs(board, valid+1):
                return True
            board[min_i][min_j] = '.'
            
        return False
                

    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        valid = 0
        for r in board:
            for c in r:
                if c != '.':
                    valid += 1
                    
        self.dfs(board, valid)
        
        
        
sudoku = ["..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."]
sudoku = [[c for c in s] for s in sudoku]
s = Solution()
s.solveSudoku(sudoku)
print sudoku