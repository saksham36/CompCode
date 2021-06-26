class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0; i<nums.size();i++)
            if(nums[i]==0)
                nums[i] = -1;
        int pre_sum=0, res = 0;
        unordered_map<int, int> h;
        for(int i=0; i<nums.size();i++){
            pre_sum += nums[i];
            // cout<<"Pre: "<<pre_sum<<endl;
            if(pre_sum == 0){
                // cout<<"From beg"<<endl;
                res = max(res, i+1);
            }
            else if(h.find(pre_sum) != h.end()){
                auto it = h.find(pre_sum);
                res = max(res, (i-it->second));
                // cout<< i<<" "<< it->second<<endl;
            }
            else //store min id only
                h.insert({pre_sum, i});
        }

        return res;
    }
};