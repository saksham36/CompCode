class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> v(nums.size(), -1);
        for(int i=0; i< 2*nums.size()-1; i++){
            // cout<<"i = "<<i<<" "<<nums[i%nums.size()]<<endl;
            while(!s.empty() && nums[s.top()] < nums[i%nums.size()]){
                // cout<<s.top()<<"->"<<nums[s.top()]<<endl;
                // cout<<"Ans: "<<v[s.top()]<<endl;
                v[s.top()] = nums[i%nums.size()];
                // cout<<"Updated ans: "<<v[s.top()]<<endl;
                s.pop();
            }
            s.push(i%nums.size());

        }
        return v;
    }
};