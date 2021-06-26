class Solution {
public:
    static bool myCmp(const vector<int>& a, const vector<int>&b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), myCmp);
        int idx = 0;
        
        for(int i=1; i<intervals.size(); i++){
            if(max(intervals[idx][0], intervals[i][0]) <= min(intervals[idx][1], intervals[i][1])){
                intervals[idx][1] = max(intervals[idx][1], intervals[i][1]);
                intervals[idx][0] = min(intervals[idx][0], intervals[i][0]);
            }
            else{
                idx++;
                intervals[idx] = intervals[i];
                
            }
        }
        for(int i=0;i<=idx;i++){
            res.push_back(intervals[i]);
        }
        return res;
    }
};