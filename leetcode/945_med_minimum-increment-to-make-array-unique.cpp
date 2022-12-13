class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int move = 0;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= prev)
            {
                prev++;
                move += (prev - nums[i]);
            }
            else
                prev = nums[i];
        }
        return move;
    }
};