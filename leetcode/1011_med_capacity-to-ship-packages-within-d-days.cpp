class Solution {
public:
    bool isFeasible(vector<int>&weights, int k, int ans){
        int req = 1, sum = 0;
        for(int x: weights){
            if (sum+x > ans){
                req++;
                sum = x;
            }
            else
                sum += x;
        }
        return req<= k;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0, mx = 0;
        for(int x:weights){
            sum += x;
            mx = max(mx, x);
        }
        
        int low = mx, high = sum, res = 0, mid;
        while(low<=high){
            mid = (low+high)/2;
            if(isFeasible(weights, days, mid)){
                res = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return res;
        
    }
};