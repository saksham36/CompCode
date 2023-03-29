class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> map;
        int result = 0;
        int i = 0;
        int max_freq = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (map.count(s[j]) != 0)
                map[s[j]]++;
            else
                map[s[j]] = 1;
            max_freq = max(max_freq, map[s[j]]);
            while ((j - i + 1) - max_freq > k)
            { // Not valid substring, move left pointer
                map[s[i]]--;
                i++;
            }
            result = max((j - i + 1), result);
        }

        return result;
    }
};
Console
