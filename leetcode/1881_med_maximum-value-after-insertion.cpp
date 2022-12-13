class Solution {
public:
    string maxValue(string n, int x) {
        bool is_negative = false, added_x = false;
        if(n[0]=='-') 
            is_negative = true;
        char x_char = x + '0';
        string result = "";
        for(int i=0; i< n.length(); i++){
            if(is_negative && i == 0){
                result += n[i];
                continue;
            } 
            if(!added_x){
                if((n[i]<= x_char && is_negative) || (n[i]>=x_char && !is_negative))
                    result += n[i];
                else{
                    result += x_char;
                    result += n[i];
                    added_x = true;
                }
            }
            else
                result += n[i];
        }
        if(!added_x)
            result += x_char;
        return result;

    }
};