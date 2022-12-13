class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<int> row_direction = {0,1,0,-1};
        vector<int> col_direction = {1,0,-1,0};
        vector<vector<int>>result(rows*cols, vector<int>(2, 0));
        int t = 0, steps, row_step=rStart, col_step=cStart;
        vector<int> tmp{rStart, cStart};
        result[t++] = tmp;

        for(int k=1; k< 2*(rows*cols); k+=2){
            for(int i=0; i<4;++i){ // new direction 
                steps = k + (i/2);
                for(int j=0; j<steps; j++){
                    row_step += row_direction[i];
                    col_step += col_direction[i];
                    if(0<= row_step && row_step < rows && 0 <= col_step && col_step < cols){
                        vector<int>tmp = {row_step, col_step};
                        result[t++] = tmp;
                        if(t == rows * cols) 
                            return result;
                    }

                }
            }
        }
        return result;

    }
};