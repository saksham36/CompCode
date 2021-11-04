class Solution {
public:
    int recursive(vector<vector<int>>&Q, int low, int high){
        // cout<<"low: "<<low<<" high: "<<high<<endl;
        if(low >= high) return 0;
        if(Q[low][high] >= 0)
            return Q[low][high];
        int temp;
        int res = INT_MAX;
        for(int i=low; i<=high; i++){
            temp = i + max(recursive(Q, low, i-1), recursive(Q, i+1, high));
            res = min(res, temp);
        }
        Q[low][high] = res;
        return res;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> Q(n+1, vector<int>(n+1, -1));
        return recursive(Q, 1, n);
    }
};
