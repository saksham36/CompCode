class Solution {
public:
    int mergeCount(vector<int>&nums, int l, int m, int r){
        vector<int>left, right;
        int n1 = m-l+1;
        int n2 = r-m;
        for(int i=0; i<n1; i++)
            left.push_back(nums[l+i]);
        for(int i=0; i<n2; i++)
            right.push_back(nums[i+m+1]);
        int i = 0, j = 0, k = l, res = 0;
        while(i<n1 && j<n2){
            if(left[i]<= right[j]){
                nums[k++] = left[i++];
            }
            else{
                nums[k++] = right[j++];
                res += n1 - i;
            }                
        }
        while(i <n1)
            nums[k++] = left[i++];
        while(j<n2)
            nums[k++] = right[j++];
        return res;
    }
    
    int countInversion(vector<int>&nums, int l, int r){
        int res = 0;
        if(l<r){
            int m = l + (r-l)/2;
            res += countInversion(nums, l, m);
            res += countInversion(nums, m+1, r);
            res += mergeCount(nums, l, m, r);
        }
        return res;
    }
    bool isIdealPermutation(vector<int>& nums) {
        int local = 0;
        for(int i=0; i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                local++;
            }
        }
        int global = countInversion(nums, 0, nums.size()-1);
        // cout<<"Local: "<<local<<endl;
        // cout<<"Global: "<<global<<endl;
        return global == local;
    }
};