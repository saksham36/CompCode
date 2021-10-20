class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>>grp(n+1, vector<int>(n+1, -1));
        vector<int>dist(n+1, 1e9);    
        for (int i = 1; i <= n; ++i)
            grp[i][i] = 0;
        for (auto& e : times)
            grp[e[0]][e[1]] = e[2];
    
        priority_queue<pair<int, int>> pq;//cost, node
        pq.push({0, k});
        dist[k] = 0;
        
        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            for (int i = 1; i <= n; i++) {
                if (grp[node][i] == -1)
                    continue;
                int newCost = dist[node] + grp[node][i];
                if (newCost < dist[i]) {
                    pq.push({newCost, i});
                    dist[i] = newCost;   
                }
            } 
        }
        
        int maxDist = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9)
                return -1;
            else
                maxDist = max(maxDist, dist[i]);
        }
        
        return maxDist;
    }
};