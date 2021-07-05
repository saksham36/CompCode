class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int curr, res = 0, tmp;
        stack<int> s;
        for(int i = 0; i<heights.size(); i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                tmp = s.top();
                s.pop();
                curr = heights[tmp] * (s.empty()? i: (i- s.top() - 1));
                res = max(res, curr);
            }
            s.push(i); //previous smaller. element just beneath
        }
        while(!s.empty()){
            tmp = s.top();
            s.pop();
            curr = heights[tmp] * (s.empty()? heights.size(): (heights.size()- s.top() - 1));
            res = max(res, curr);
        }
        return res;
        
    }
};