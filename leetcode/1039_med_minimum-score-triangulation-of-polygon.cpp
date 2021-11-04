class Solution
{
public:
    int recursion(vector<int> &value, int i, int j, vector<vector<int> > &dp)
    {
        // cout<<"i: "<<i<<" j: "<<j<<endl;
        if (dp[i][j] != 0)
            return dp[i][j];
        int res = 0;
        for (int k = i + 1; k < j; k++)
        {
            res = min(res == 0 ? INT_MAX : res, value[i] * value[k] * value[j] + recursion(value, i, k, dp) + recursion(value, k, j, dp));
        }
        // cout<<"i: "<<i<<" j: "<<j<<" res: "<<res<<endl;
        dp[i][j] = res;
        return res;
    }
    int minScoreTriangulation(vector<int> &values)
    {
        vector<vector<int> > dp(values.size(), vector<int>(values.size(), 0));
        return recursion(values, 0, values.size() - 1, dp);
    }
};