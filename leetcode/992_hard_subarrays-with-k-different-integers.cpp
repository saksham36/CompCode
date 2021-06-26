class Solution {
public:
    int atMostKGet(vector<int>& nums, int k){
        int ans = 0;
        unordered_map<int, int>m;
        int i = 0;
        for(int j=0;j<nums.size();j++){
            m[nums[j]]++;
            while(i<=j && m.size()>k){
                m[nums[i]]--;
                if(m[nums[i]]==0)
                    m.erase(nums[i]);
                i++;
            }
            ans+=j-i+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return atMostKGet(nums, k) - atMostKGet(nums, k-1);
    }
};
