class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<=j){
            // cout<<i<<" "<<j<<" "<<s[i]<<" "<<s[j]<<endl;
            if(isalpha(s[i]) && isalpha(s[j])){
                if(tolower(s[i])==tolower(s[j])){
                    i++;
                    j--;
                }
                else 
                    return false;
            }
            else if(isdigit(s[i]) && isdigit(s[j])){
                if(s[i]==s[j]){
                    i++;
                    j--;
                }
                else 
                    return false;
            }
            else if((isdigit(s[i]) && isalpha(s[j]) ) || (isdigit(s[j]) && isalpha(s[i]) ))
                    return false;
            else if(!(isalpha(s[i]) || isdigit(s[i])))
                i++;
            else if(!(isalpha(s[j]) || isdigit(s[j])))
                j--;
        }
       return true; 
    }
};