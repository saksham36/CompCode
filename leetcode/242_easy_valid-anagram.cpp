class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        unordered_map<char, int> m;
        for(char x: s)
            m[x]++;
        for(char x: t){
            m[x]--;
            if(m[x] == 0)
                m.erase(x);
        }
        if(m.size()==0)
            return true;
        else
            return false;
        
    }
};