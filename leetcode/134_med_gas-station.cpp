class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        queue<int> dq;
        int curr = 0, i = 0;
        while(dq.size() != gas.size()){
            dq.push(i);
            curr += gas[i] - cost[i];
            i = (i+1) % gas.size();
            while(!dq.empty() && curr <0){
                curr -= (gas[dq.front()] - cost[dq.front()]);
                if(dq.front() == gas.size()-1)
                    return -1;
                dq.pop();
            }
            
        }
        return dq.front();
    }
};