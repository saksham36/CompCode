class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>c{1};
        c.reserve(ratings.size());
        for(int i=1;i<ratings.size();i++){
            if(ratings[i] > ratings[i-1])
                c.push_back(c[i-1]+1);
            else
                c.push_back(1);
        }
        // for(int x: c)
        //     cout<<x<<" ";
        // cout<<endl;
        int sum = c[c.size()-1];
        for(int i=c.size()-2; i>=0; i--){
            if(ratings[i]>ratings[i+1] && c[i]<=c[i+1]){
                c[i] = c[i+1] +1;
            }
            sum += c[i];
        }
        // for(int x: c)
        //     cout<<x<<" ";
        // cout<<endl;
        return sum;
        
    }
};