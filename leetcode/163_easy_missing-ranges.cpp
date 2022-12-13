class Solution
{
public:
    string formatRange(int lower, int upper)
    {
        if (lower == upper)
        {
            return to_string(lower);
        }
        return to_string(lower) + "->" + to_string(upper);
    }

    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper)
    {
        int prev = lower - 1;
        int curr;
        vector<string> res;
        for (int i = 0; i <= nums.size(); i++)
        {
            // cout<<"i: "<<i<<" prev: "<<prev<<endl;
            curr = (i < nums.size()) ? nums[i] : upper + 1; // ternary fails only on last iteration. Check last boundary
            // cout<<"curr: "<<curr<<endl;
            if (prev + 1 <= curr - 1)
            {
                res.push_back(formatRange(prev + 1, curr - 1));
            }
            prev = curr;
        }
        return res;
    }
};

Console
