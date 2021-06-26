class Solution {
public:
    static bool myCmp(pair<int,int> p1,pair<int,int> p2){
        return p1.second > p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        for(int x: nums){
            m[x]++;
        }
        vector<pair<int,int> > v;
        for(auto p:m) 
            v.push_back(p);
        
        sort(v.begin(), v.end(), myCmp);
        
        vector<int>res;
        for(int i=0;i<k;i++)
            res.push_back(v[i].first);
        return res;
    }
};