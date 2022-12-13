class Solution {
private:
    bool isCyclic(int current, unordered_map<int, vector<int>>&dict, vector<bool>&checked, vector<bool>&path) {
        // current checked. No cycle would be formed with this node
        if(checked[current])
            return false;
        // detecting previously visited node -> cycle
        if(path[current])
            return true;
        path[current] = true;
        // Backtrack
        bool result = false;
        for(int child: dict[current]){
            result = isCyclic(child, dict, checked, path);
            if(result)
                break;

        }
        // Reset current path
        path[current] = false;
        checked[current] = true;
        return result;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> dict;

        // Making graph
        for(auto &prereq: prerequisites){
            if(dict.count(prereq[1])){
                dict[prereq[1]].push_back(prereq[0]);
            }
            else{
                vector<int>tmp {prereq[0]};
                dict[prereq[1]] = tmp;
            }
        }

        vector<bool> checked(numCourses);
        vector<bool> path(numCourses);

        for(int i=0; i<numCourses; i++){
            if(isCyclic(i, dict, checked, path))
                return false;
        }
        return true;
    }
};