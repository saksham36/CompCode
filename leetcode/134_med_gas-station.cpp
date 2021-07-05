class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr =0, prev = 0, start = 0;
        for(int i=0; i<gas.size();i++){
            curr += gas[i] - cost[i];
            if(curr < 0){
                prev += curr;
                curr = 0;
                start = i+1;
            }
        }
        return (prev+curr >=0)?start: -1;
    }
};