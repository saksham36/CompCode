class Solution {
public:
    int myAtoi(string s) {
        // cout<<"*"<<endl;
        int i = 0;
        while(s[i] == ' ' && i != s.size()-1)
            i++;
        int sign = 1;
        if(s[i] == '-'){
            sign = -1;
            i++;
            }
        else if(s[i] == '+')
            i++;
        long res = 0;
        while(i<s.size()){
            if(s[i]>'9' || s[i] < '0') //no more numbers
                break; 
            else{
                // cout<<s[i]<<endl;
                res *= 10;
                res+=s[i]-'0';
                if(sign*res>=INT_MAX) return INT_MAX;
                if (sign*res<=INT_MIN) return INT_MIN;
                // cout<<"Res: "<<res<<endl;
            }
            i++;
        }
        return sign*res;
        
    }
};