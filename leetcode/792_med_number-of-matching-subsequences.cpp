class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0;
        vector<vector<int>>map(26);
        for(int i=0;i<s.size();i++){
            map[s[i] - 'a'].push_back(i);
        }
        for(string word: words){
            // cout<<word<<endl;
            bool found = true;
            for(int i = 0, prev = -1; found && i < size(word); i++) {
                auto& v = map[word[i]-'a'];
                auto it = upper_bound(begin(v), end(v), prev);   
                if(it == end(v)) found = false;                  // doesn't exist
                else prev = *it;                                 // update prev for next check
            }
            res += found;
            // cout<<found<<endl;
            
        }
        return res;
    }
};