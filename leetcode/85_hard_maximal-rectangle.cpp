class Solution {
public:
    int maxHist(vector<int>arr){
        stack<int> res;
        int top_val, max_area=0, area=0, i=0;
        while(i<arr.size()){
            if(res.empty() || arr[res.top()]<= arr[i])
                res.push(i++);
            else{
                top_val = arr[res.top()];
                res.pop();
                area = top_val * i;
                if(!res.empty())
                    area = top_val * (i - res.top()-1);
                max_area = max(area, max_area);
            }
        }
        while(!res.empty()){
            top_val = arr[res.top()];
            res.pop();
            area = top_val * i;
            if(!res.empty())
                area = top_val * (i - res.top()-1);
            max_area = max(area, max_area);
        }
        return max_area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        vector<vector<int> > mat(matrix.size(),vector<int>(matrix[0].size()));
        for(int i = 0; i<matrix.size(); i++)
            for(int j=0; j< matrix[0].size();j++)
                    mat[i][j] = matrix[i][j] - 48;
        
        int res = maxHist(mat[0]);
        for(int i = 1; i<matrix.size(); i++){
            for(int j=0; j< matrix[0].size();j++){
                if(mat[i][j] == 1)
                    mat[i][j] += mat[i-1][j];
            }
            res = max(res, maxHist(mat[i]));
        }
        return res;
    }
};