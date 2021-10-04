class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sums = 0;
        for(int x: nums)
            sums+=x;
        
        if(nums.size() < k || sums % k != 0) return false;
        vector<int> visited(nums.size(), false);
        return backtrack(nums, visited, sums / k, 0, 0, k);
    }
    
    bool backtrack(vector<int>& nums,vector<int>visited, int target, int curr_sum, int i, int k) {
        if (k == 0) 
            return true;
        
        if (curr_sum == target) 
            return backtrack(nums, visited, target, 0, 0, k-1);
        
        for (int j = i; j < nums.size(); j++) {
            if (visited[j] || curr_sum + nums[j] > target) continue;
            
            visited[j] = true;
            if (backtrack(nums, visited, target, curr_sum + nums[j], j+1, k)) return true;
            visited[j] = false;
        }
        
        return false;
    }
};