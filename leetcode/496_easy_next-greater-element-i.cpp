class Solution {
public:
    int findNextGreater(int x, vector<int>&nums){
        auto it = find(nums.begin(), nums.end(), x);
        int t=it-nums.begin();
        
        for(int i=t;i<nums.size();i++)
        {
            if(nums[i]>x) return nums[i];
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        for(int x: nums1){
            v.push_back(findNextGreater(x, nums2));
        }
        return v;
    }
};