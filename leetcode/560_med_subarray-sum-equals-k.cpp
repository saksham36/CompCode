class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> h;
        int res = 0, pre_sum = 0;
        h[0] = 1;
        for(int x: nums){
            pre_sum += x;
            if(h.find(pre_sum-k)!=h.end()) {
                res += h[pre_sum-k];
            }
            h[pre_sum]++;
        }
        return res;
    }
};