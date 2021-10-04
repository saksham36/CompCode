class Solution {
public:
    bool subset(vector<int> nums, unordered_map <int, bool> &dp, int idx, int target){
        if(dp.count(target)) return dp[target];
        if(target==0) return true;
        if(target<0) return false;
        
        for(int i=idx; i<nums.size(); i++){
            bool possible = subset(nums, dp, i+1, target-nums[i]);
                dp[target] = possible;
            if(possible) return true;
        }
        return false;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x: nums)
            sum += x;
        unordered_map <int, bool>  m;
        if(sum%2 != 0) return false; 
        return subset(nums, m, 0, sum/2);
        }
};