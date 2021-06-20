class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int size = nums.size(), minVal = INT_MAX;
        for (int i = size - 1; i >= 2; i--)
        {
            minVal = min(minVal, nums[i]);
            if (nums[i - 2] > minVal)
            {
                return false;
            }
        }
        
        return true;
    }
};