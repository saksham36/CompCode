class Solution {
public:
    int jump(vector<int>& nums) {
        // Dynamic programming: O()N^2)
        // Greedy
        int result = 0, left=0, right=0, farthest;
        while(right< nums.size()-1){
            farthest = 0;
            for(int i=left; i<right+1; i++){
                farthest = max(farthest, i+ nums[i]);
            }
            left = right + 1;
            right = farthest;
            result +=1;
        }
        return result;
    }
};