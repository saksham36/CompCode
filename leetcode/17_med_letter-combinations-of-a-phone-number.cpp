class Solution
{
public:
    void backtrack(vector<string> &ans, unordered_map<char, string> &m, string digits, string temp, int i, int n)
    {
        if (i == n)
        {
            ans.push_back(temp);
            return;
        }
        for (int k = 0; k < m[digits[i]].size(); k++)
        {
            temp.push_back(m[digits[i]][k]);
            backtrack(ans, m, digits, temp, i + 1, n);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.length() == 0)
            return ans;

        unordered_map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        backtrack(ans, m, digits, "", 0, digits.size());
        return ans;
    }
};