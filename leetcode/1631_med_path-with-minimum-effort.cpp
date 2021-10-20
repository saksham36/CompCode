class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> dist(heights.size(), vector<int>(heights[0].size(), INT_MAX));

        auto comp = [](pair<int,vector<int>> &a, pair<int,vector<int>> &b) -> bool {return a.first > b.first;};
        // effort to reach point
        priority_queue<pair<int, vector<int>> ,vector<pair<int,vector<int>>>, decltype(comp)> q(comp);
        vector<int>temp(2, 0);
        q.push({0,temp});
        dist[0][0] = 0;
        int row, col, row_t, col_t;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty()){
            auto[effort, v] = q.top();
            // cout<<"V: ("<< v[0]<<" , "<<v[1]<<") effort: "<<effort<<endl;
            row = v[0];
            col = v[1];
            q.pop();
            if(row == heights.size()-1 && col == heights[0].size()-1) return effort;
            for(int i = 0; i < 4; i++) {
                // cout<<"Direction: ("<<dirs[i][0]<<" , "<<dirs[i][1]<<")\n";
                row_t = row + dirs[i][0];
                col_t = col + dirs[i][1];
                if(row_t>=0 && row_t<heights.size() && col_t>=0 && col_t<heights[0].size()){
                    temp = {row_t, col_t};
                    if(max(effort, abs(heights[row][col]-heights[row_t][col_t])) < dist[row_t][col_t]){
                        dist[row_t][col_t] = max(effort, abs(heights[row][col]-heights[row_t][col_t]));
                        q.push({dist[row_t][col_t], temp});
                    }
                }
            }
        }
        
        return INT_MAX;
    }
};