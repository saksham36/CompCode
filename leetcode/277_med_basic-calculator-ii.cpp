class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        if(len == 0)
            return 0;
        char current, operation = '+';
        int current_num = 0;
        stack<int> st;
        for(int i=0; i<len;i++){
            current = s[i];
            if(isdigit(current)){
                current_num = (current_num * 10) + (current - '0');
            }
            if(!isdigit(current) && !iswspace(current) || i == len-1){
                if(operation == '-')
                    st.push(-current_num);
                else if(operation == '+')
                    st.push(current_num);
                else if(operation == '*'){
                    int top_num = st.top();
                    st.pop();
                    st.push(top_num*current_num);
                }
                else if(operation == '/'){
                    int top_num = st.top();
                    st.pop();
                    st.push(top_num/current_num);
                }
                operation = current;
                current_num = 0;
            }
        }
        int result = 0;
        while(st.size() != 0){
            result += st.top();
            st.pop();
        }
        return result;
    }
};