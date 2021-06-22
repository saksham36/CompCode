class Solution {
public:
    void swap(vector<int>&nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    int lomuto(vector<int>&nums, int l, int h){
        int pivot = nums[h];
        int i = l - 1, tmp;
        for(int j = l; j<h; j++){
            if(nums[j] < pivot){
                i++;
                swap(nums, i, j);
            }
        }
        swap(nums, i+1, h);
        return i+1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size()-1, p;
        while(l<=r){
            p = lomuto(nums, l, r);
            // cout<<"p: "<<p<<" idx: "<< nums.size()-p<<" nums: "<< nums[p]<<endl;
            if(nums.size()-p==k)
                return nums[p];
            else if(nums.size()-p>k)
                l = p+1;
            else
                r = p-1;
            
        }
    return -1;
    }
};