class Solution {
public:
    
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
    int grid_size = 1000000;
    if(target[0]>= grid_size || target[1]>= grid_size 
       || target[0]< 0 || target[1]< 0){
        return false;
    }
    if(blocked.size() < 2) return true;
        
    set<pair<int,int>> visited, obstacles;
    int y = grid_size-1, x = grid_size-1;
    
    for(auto &b: blocked) obstacles.insert({b[1],b[0]});
    
    queue<pair<int,int>> q;
    q.push({source[1], source[0]});
    int lim = blocked.size();
        
    while(!q.empty()){
      if(--lim == 0) goto mark;
      int n = q.size();
      while(n){
        n--;
        auto[ty, tx] = q.front(); 
        q.pop();
        if(visited.count({ty,tx})) 
            continue;
        if(ty == target[1] && tx == target[0]) 
            return true;
        visited.insert({ty,tx});
        if(ty && !visited.count({ty-1,tx}) && !obstacles.count({ty-1,tx}))                      q.push({ty-1, tx});
        if(tx && !visited.count({ty,tx-1}) && !obstacles.count({ty,tx-1}))                      q.push({ty, tx-1});
        if(ty != y && !visited.count({ty+1,tx}) && !obstacles.count({ty+1,tx}))                 q.push({ty+1, tx});
        if(tx != x && !visited.count({ty,tx+1}) && !obstacles.count({ty,tx+1}))                 q.push({ty, tx+1});
      }
    }
    return false;
    mark:;
    
    visited.clear();
    while(!q.empty()) 
        q.pop();
    q.push({target[1], target[0]});
    lim = blocked.size();
    while(!q.empty()){
      if(--lim == 0) return true;
      int n = q.size();
      
      while(n--){
        auto[ty, tx] = q.front(); q.pop();
        if(visited.count({ty,tx})) continue;
        visited.insert({ty,tx});
      
        if(ty && !visited.count({ty-1,tx}) && !obstacles.count({ty-1,tx}))                      q.push({ty-1, tx});
        if(tx && !visited.count({ty,tx-1}) && !obstacles.count({ty,tx-1}))                      q.push({ty, tx-1});
        if(ty != y && !visited.count({ty+1,tx}) && !obstacles.count({ty+1,tx}))                 q.push({ty+1, tx});
        if(tx != x && !visited.count({ty,tx+1}) && !obstacles.count({ty,tx+1}))                 q.push({ty, tx+1});
      }
    }
    
    return false;
  }
};