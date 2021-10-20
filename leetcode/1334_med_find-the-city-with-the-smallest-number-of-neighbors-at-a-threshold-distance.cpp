class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Create adjancency matrix
        vector<vector<int>>matrix(n, vector<int>(n, INT_MAX));
        for(auto x: edges){
            matrix[x[0]][x[1]] = x[2];
            matrix[x[1]][x[0]] = x[2];
            matrix[x[0]][x[0]] = 0;
            matrix[x[1]][x[1]] = 0;
        }
        // Floyd Warsahl algorithm
        for(int i=0; i<n; i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(matrix[k][i] == INT_MAX || matrix[i][j] == INT_MAX) continue;
                    matrix[k][j] = min(matrix[k][j], matrix[k][i]+matrix[i][j]);
                    matrix[j][k] = matrix[k][j];
                }
            }
        }
        int minCount = INT_MAX;
        int count, vertex = -1;
        for(int i=0; i<n; i++){
            count = 0;
            for(int j=0; j<n;j++){
                if(i == j || matrix[i][j] == INT_MAX) continue;
                if(matrix[i][j] <= distanceThreshold)
                    count++;
            }
            // cout<<"i: "<<i<<" Cities: "<<count<<endl;
            if(count <= minCount){
                minCount = count;
                vertex = i;
            }
        }
        
        return vertex;
    }
};