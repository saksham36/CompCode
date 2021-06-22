class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        vector<int> row;
        for(int r=1;r<=numRows;r++){
            row.push_back(1);
            vector<int>tmp = row;
            cout<<pascal.size()<<endl;
            for(int j=1; j<tmp.size()-1; j++)
                tmp[j] = pascal[pascal.size()-1][j-1]+pascal[pascal.size()-1][j];
            pascal.push_back(tmp);
        }
        return pascal;
    }
};