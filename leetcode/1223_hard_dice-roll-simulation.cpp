class Solution
{
public:
    long long mod = 1000000007;
    int recursive(int n, vector<vector<vector<long long> > > &dp, vector<int> &roll, int prev, int count)
    {
        if (n == 0)
            return 1;
        // cout<<n<<" "<<prev<<" "<<count<<": "<<dp[n][prev][count]<<endl;
        if (dp[n][prev][count] != -1)
            return dp[n][prev][count];

        long long int res = 0;

        for (int i = 0; i < 6; i++)
        {
            if (i == prev && count >= roll[i])
                continue;
            if (i == prev)
            {
                res = (res + recursive(n - 1, dp, roll, prev, count + 1)) % mod;
            }
            else
                res = (res + recursive(n - 1, dp, roll, i, 1)) % mod;
        }
        return dp[n][prev][count] = res;
    }
    int dieSimulator(int n, vector<int> &rollMax)
    {
        vector<vector<vector<long long> > > dp(n + 1, vector<vector<long long> >(6, vector<long long>(16, -1)));
        // cout<<dp.size()<<endl;
        // cout<<dp[0].size()<<endl;
        // cout<<dp[0][0].size()<<endl;
        return recursive(n, dp, rollMax, 5, 0);
    }
};