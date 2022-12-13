class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time_needed, total_time=0, curr_max_time = 0;
        for (int i = 0; i < colors.size(); i++) {
            // New group
            if(i > 0 && colors[i] != colors[i-1]){
                curr_max_time = 0;
            }
            total_time += min(curr_max_time, neededTime[i]);
            curr_max_time = max(curr_max_time, neededTime[i]);
        }
        return total_time;
    }
};