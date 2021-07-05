class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        // cout<<(int)'['<<" "<<(int)']'<<endl;
        // cout<<(int)'('<<" "<<(int)')'<<endl;
        // cout<<(int)'{'<<" "<<(int)'}'<<endl;
        for(char x: s){
            // cout<<x<<endl;
            if(x == '(' || x == '{' || x == '['){
                st.push(x);
            }
            else if(st.empty())
                return false;
            else if(x == ')'){
                if (st.top() == '(')
                    st.pop();
                else 
                    return false;
            }
            else if(x == '}'){
                if(st.top() == '{')
                    st.pop();
                else 
                    return false;
            }
            else if(x == ']'){
                if(st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};