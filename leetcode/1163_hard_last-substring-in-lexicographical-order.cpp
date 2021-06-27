class Solution {
public:
    string lastSubstring(string s) {
        char max = s[0];
        int max_idx = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] >max){
                max_idx = i;
                max = s[i];
            }
            else if(s[i] == max){  
                int j = 1;
                while(s[i+j] == s[max_idx+j] && max_idx + j < i) //if duplicates, we don't want to update max_idx
                    j++;
                if(s[i+j] > s[max_idx + j])  //ith is actually higher rank
                    max_idx = i;
                i = i + j - 1; // skip i's if repeating
                
            }
        }
        return s.substr(max_idx, s.length()-max_idx+1);
    }
};