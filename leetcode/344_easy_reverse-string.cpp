class Solution {
public:
    void swap(vector<char>&s, int i, int j){
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
    void reverseString(vector<char>& s) {
        int n = s.size()/2;
        for(int i=0; i<n; i++){
            swap(s, i, s.size()-1-i);
        }
    }
};