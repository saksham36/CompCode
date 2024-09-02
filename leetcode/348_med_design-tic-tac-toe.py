import numpy as np
class TicTacToe(object):

    def __init__(self, n):
        """
        :type n: int
        """
        self.n = n
        self.row_counter = np.zeros(n, dtype=int)
        self.column_counter = np.zeros(n, dtype=int)
        self.diag_counter = 0
        self.anti_diag_counter = 0

    def move(self, row, col, player):
        """
        :type row: int
        :type col: int
        :type player: int
        :rtype: int
        """
        if row >= self.n or col >= self.n:
            return 0
        score = 2 * player - 3 # 1-> -1, 2-> 1
        self.row_counter[row] += score
        if abs(self.row_counter[row]) == self.n:
            return player
        
        self.column_counter[col] += score
        if abs(self.column_counter[col]) == self.n:
            return player
        
        if row == col:
            self.diag_counter += score
            if abs(self.diag_counter) == self.n:
                return player
        
        if row == self.n - 1 - col:
            self.anti_diag_counter += score
            if abs(self.anti_diag_counter) == self.n:
                return player
        
        return 0

# Your TicTacToe object will be instantiated and called as such:
# obj = TicTacToe(n)
# param_1 = obj.move(row,col,player)
