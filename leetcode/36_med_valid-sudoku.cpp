class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> col_num(9); // each element represent 1 column
        vector<int> grid(9); // each element represent 1 grid
        for(int row=0;row<9;row++) {
            int row_num=0;
            for(int col=0;col<9;col++) {
                if(board[row][col]!='.') {
                    // 1 -> 1, 2 -> 2, 3-> 4. Basically check the first 9 bits represent if the (1st order) index number is present
                    int num=1<<(board[row][col]-'1');
                    // cout<<board[row][col]<<" "<< num<<endl;
                    if(row_num&num || col_num[col]&num || grid[col/3+3*(row/3)]&num)
                        return false;
                    // Update row and column
                    row_num|=num;
                    col_num[col]|=num;
                    grid[col/3+3*(row/3)]|=num;
                }
            }
        }
    return true;
    }
};