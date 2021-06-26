class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for(int x: arr){
            auto it = m.find(x);
            if(it == m.end()){
                m.insert({x,1});
            }
            else
                m.insert({x,++it->second});
        }
        cout<< m.size()<<endl;
        bool res = true;
        unordered_set<int> s;
        for(auto x: m){
            auto it = s.find(x.second);
            if(it ==s.end()){
                s.insert(x.second);
            }
            else{
                res = false;
                break;
            }
        }
        
        return res;
    }
};