class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        if(moves.size() < 3)
            return "Pending";
        int n = 3;
        vector<int>row_score(n,0);
        vector<int>col_score(n,0);
        int diag_score = 0, anti_diag_score = 0;
        int row, col;
        int player = 1;
        for(auto move: moves){
            row = move[0];
            col = move[1];
            row_score[row] += player;
            col_score[col] += player;
            // Update diag_score
            if(row == col)
                diag_score += player;
            // Update anti_diag_score
            if (row + col == n - 1) {
                anti_diag_score += player;
            }
            
            // Winning conditions
            if (abs(row_score[row]) == n || abs(col_score[col]) == n || 
                abs(diag_score) == n || abs(anti_diag_score) == n) {
                return player == 1 ? "A" : "B";
            }

            // Change player
            player *= -1;
        }
        // If grid full -> Draw, else -> Pending
        return moves.size() == n * n ? "Draw" : "Pending";
    }
};