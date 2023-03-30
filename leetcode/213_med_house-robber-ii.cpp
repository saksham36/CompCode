class Solution
{
public:
    int rob_simple(vector<int> &nums)
    {

        int N = nums.size();
        vector<int> max_robbed(N + 1, 0);

        max_robbed[N] = 0;               // robber has no houses left to rob. 0 profit
        max_robbed[N - 1] = nums[N - 1]; // Last house left to rob

        for (int i = N - 2; i >= 0; i--)
        {
            max_robbed[i] = max(max_robbed[i + 1], max_robbed[i + 2] + nums[i]);
        }

        return max_robbed[0];
    }

    int rob(vector<int> &nums)
    {

        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];

        vector<int> option_a(nums.begin(), nums.end() - 1);
        vector<int> option_b(nums.begin() + 1, nums.end());
        return max(rob_simple(option_a), rob_simple(option_b));
    }
};