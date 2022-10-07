class Solution
{
public:
    void generateParenthesisUtil(int n, int open, int close, string s, vector<string> &res)
    {
        if (open == n && close == n)
        {
            res.push_back(s);
            return;
        }
        if (open < n)
            generateParenthesisUtil(n, open + 1, close, s + "(", res);
        if (close < open)
            generateParenthesisUtil(n, open, close + 1, s + ")", res);
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        generateParenthesisUtil(n, 0, 0, "", res);
        return res;
    }
};