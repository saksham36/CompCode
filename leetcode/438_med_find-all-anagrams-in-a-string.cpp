class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> m_s;
        unordered_map<char,int> m_p;
        for(int i=0; i<p.length(); i++){
            m_s[s[i]]++;
            m_p[p[i]]++;
        }
        vector<int> res;
        for(int i=p.length(); i<s.length();i++){
            if(m_s == m_p)
                res.push_back(i-p.length());
            m_s[s[i]]++;
            m_s[s[i-p.length()]]--;
            if(m_s[s[i-p.length()]] == 0)
                m_s.erase(s[i-p.length()]);
        }
        if(m_s == m_p)
            res.push_back(s.length()-p.length());
        return res;
        
    }
};