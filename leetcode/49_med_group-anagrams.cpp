class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        if (strs.size() == 0)
            return result;
        unordered_map<string, vector<string>> map;
        for (auto s : strs)
        {
            vector<int> count(26, 0);
            for (auto c : s)
            {
                count[int(c) - 97]++; // int('a') = 97
            }
            vector<char> sb;
            for (int i = 0; i < 26; i++)
            {
                sb.push_back('.');
                sb.push_back(count[i]);
            }
            string str(sb.begin(), sb.end());
            if (map.count(str) == 0)
            {
                vector<string> temp;
                map.insert({str, temp});
            }
            map[str].push_back(s);
        }
        for (auto itr = map.begin(); itr != map.end(); itr++)
        {
            result.push_back(itr->second);
        }
        return result;
    }
};