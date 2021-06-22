class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1};        
        vector<int>curr, prev = row;
        for(int r=1;r<=rowIndex+1;r++){
            curr = row;
            for(int j=1; j<curr.size()-1; j++)
                curr[j] = prev[j-1]+prev[j];
            row.push_back(1);
            prev = curr;
        }
        return curr;
    }
};