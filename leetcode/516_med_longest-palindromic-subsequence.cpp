class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        vector<vector<short>> m(2, vector<short>(s.size() + 1));
        // cout<<"s.size(): "<<s.size()<<endl;
        for (int i = 1; i <= s.size(); i++){
            for (int j = s.size()-1; j >=0; j--){
                // cout<<"i: "<<i<<" j: "<< j<<endl;
                // cout<<s[j]<<endl;
                if (s[i - 1] == s[j]) m[i % 2][j] = m[(i -1) % 2][j + 1] + 1;
                else m[i % 2][j] = max(m[(i - 1) % 2][j], m[i % 2][j + 1]);
            }
        }
        return m[s.size() % 2][0];
    }
};