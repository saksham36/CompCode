class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int smallest = INT_MAX;
        stack<pair<int,int>> s; // <prev smallest, nearest greatest>
        for(int x: nums){
            while(!s.empty() && s.top().second <= x)
                s.pop();
        if(!s.empty() && x > s.top().first)
            return true;
        s.push({smallest, x});
        smallest = min(smallest, x);
        }
        return false;
    }
};
