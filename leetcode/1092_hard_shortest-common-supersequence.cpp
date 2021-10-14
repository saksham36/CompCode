class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<short>> dp(str1.length()+1, vector<short>(str2.length()+1));
        for(int i=0; i<=str1.length(); i++)
            dp[i][0] = 0;
        for(int j=0; j<=str2.length(); j++)
            dp[0][j] = 0;
        
        for(int i=1; i<=str1.length(); i++){
            for(int j=1; j<=str2.length(); j++){
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1] +1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        // Now we have the table for finding the LCS of the 2 strings
        
        //Now we want string, start from (m+1)th row and (n+1)th column in table dp and traverse back by checking following condtions.
        string str="";
        int i=str1.length(),j=str2.length();
        while(i>0&&j>0)
        {
            if(str1[i-1]==str2[j-1]){
                str.push_back(str1[i-1]);//both are equal, so we can insert any one.
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    str.push_back(str1[i-1]);//insert the one, where we are moving
                    i--;
                }
                else{
                    str.push_back(str2[j-1]);
                    j--;
                }
            }
        }
        while(i>0){ //when string s1 remain
            str.push_back(str1[i-1]);
            i--;
        }
        while(j>0){ //when string s2 remain
            str.push_back(str2[j-1]);
            j--;
        }
        reverse(str.begin(),str.end());//since we have traversed from bottom, we need t reerse the string.
        
        return str;
    }
};