class Solution {
public:
    string reverseWords(string s) {
        int l = 0 ,r = s.length()-1 ;
        while(s[l] == ' ')
            l++ ; //removing leading spaces ;
        while(s[r] == ' ')
            r-- ; // removing trailing spaces ;
        s = s.substr(l,r-l+1) ;
        int start = 0;
        for(int end=0; end<s.length(); end++){
            while(s[start] == ' '){
                s.erase(start,1);
            }
                
            if(s[end] == ' '){
                // cout<<s[start]<< " "<<s[end-1]<<endl;
                // cout<<"Word"<<endl;
                // for(int i=start;i<=end-1;i++)
                //     cout<<s[i]<<" ";
                // cout<<endl; 
                reverse(s.begin()+start, s.begin()+end);
                // cout<<"Reverse"<<endl;
                // for(int i=start;i<=end-1;i++)
                //     cout<<s[i]<<" ";
                // cout<<endl;
                start = end+1;
            }
        }
        while(s[start] == ' ')
            start++;
        int end = s.length();
        while(s[end] == ' ')
            end--;
        // for(int i=start;i<=end;i++)
        //     cout<<s[i]<<" ";
        // cout<<endl;
        reverse(s.begin()+start, s.begin()+end);
        // for(int i=start;i<=end;i++)
        //     cout<<s[i]<<" ";
        // cout<<endl;
        // cout<<"***";
        reverse(s.begin(), s.end());
        return s;
    }
};