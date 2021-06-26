class Solution {
public:
    void swap(vector<int>&nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        }
    void sortColors(vector<int>& nums) {
       int l = 0, m = 0, h= nums.size()-1;
        while(m<=h){
            if(nums[m]==0){
                swap(nums, l, m);
                l++;
                m++;
            }
            else if(nums[m]==1)
                m++;
            else{
                swap(nums, m, h);
                h--;
            }
        }
    }
};