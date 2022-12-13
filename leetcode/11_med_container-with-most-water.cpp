class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0, left = 0, right=height.size()-1, width;
        while(left< right){
            width = right - left;
            max_area = max(max_area, min(height[left], height[right])*width);

            if(height[left] <= height[right])
                left++;
            else
                right--;
        }
        return max_area;
    }
};