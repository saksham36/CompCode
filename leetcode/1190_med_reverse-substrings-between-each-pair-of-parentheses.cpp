class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        deque<char>q;
        for(char c: s){
            if(c==')'){
                q.clear();
                while(!st.empty() && st.top() != '('){ 
                    q.push_back(st.top());
                    st.pop();
                }
                st.pop(); // remove the (
                while(!q.empty()){
                    st.push(q.front());
                    q.pop_front();
                }
                
            }
            else
                st.push(c);
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};