class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> set;
        for (int num : nums)
            set.insert(num);
        int longest_streak = 0;
        int current_num, current_streak;
        for (int num : nums)
        {
            if (set.count(num - 1) == 0)
            {
                current_num = num;
                current_streak = 1;

                while (set.count(current_num + 1) > 0)
                {
                    current_num++;
                    current_streak++;
                }
                longest_streak = max(longest_streak, current_streak);
            }
        }
        return longest_streak;
    }
};