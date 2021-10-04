class Solution {
public:
    char findTheDifference(string s, string t) {
         int n=s.length();
       
        int res=0,i;
        for(i=0;i<n;++i)
        {
            res=res^s[i]^t[i];
        }
        res^=t[i];
        return res;
    }
};