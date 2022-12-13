class Solution {
public:

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int max_val = 0;
        vector<unordered_set<int>> grid(n);
        
        for(vector<int> road : roads){
            grid[road[0]].insert(road[1]);
            grid[road[1]].insert(road[0]);
        }
        // Check for combos of 2 cities
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int curr_val = grid[i].size() + grid[j].size();
                // If city j in city i, then don't count road twice
                if(grid[i].find(j) != grid[i].end()) 
                    curr_val--;
                max_val = max(max_val, curr_val);
            }
        }
        
        return max_val;
    }
};