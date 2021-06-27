class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>prev;
        int start = 0, res = 0;
        for(int end=0; end< s.length();end++)
            prev[s[end]] = -1;
        for(int end=0; end< s.length();end++){
            start = max(start, prev[s[end]]+1);  //prev[s[end]] contains ending idx of element, start 1 after last idx of repeat 
            // cout<<"start: "<<start<<endl;
            int max_end = end - start + 1;
            // cout<<"Max_end: "<<max_end<<endl;
            res = max(res, max_end);
            prev[s[end]] = end;
            // cout<<"End: "<<s[end]<<prev[s[end]]<<endl;
        }
        return res;
    }
};