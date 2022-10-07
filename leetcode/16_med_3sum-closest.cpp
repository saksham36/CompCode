class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int front, back, diff, res, min_res = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            front = i + 1;
            back = nums.size() - 1;
            while (front < back)
            {
                diff = target - nums[i] - nums[front] - nums[back];
                if (abs(diff) < min_res)
                {
                    min_res = abs(diff);
                    res = nums[i] + nums[front] + nums[back];
                }
                if (diff > 0)
                    front++;
                else if (diff < 0)
                    back--;
                else
                    return target;
            }
        }
        return res;
    }
};