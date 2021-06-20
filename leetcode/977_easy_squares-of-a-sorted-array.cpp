class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        vector<int> vect(nums.size(),0);
        for(int k=vect.size()-1; k>=0;k--){
            if(nums[i]*nums[i] > nums[j]*nums[j]){
                vect[k] = nums[i]*nums[i++];
            }
            else
                vect[k] = nums[j]*nums[j--];
        }
        return vect;
    }
};