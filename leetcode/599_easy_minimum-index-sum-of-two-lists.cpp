class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        unordered_map<string, int> map;
        for (int i = 0; i < list1.size(); i++)
        {
            map[list1[i]] = i;
        }
        vector<string> res;
        int mi = INT_MAX;
        for (int i = 0; i < list2.size() && i <= mi; i++)
        {
            if (map.find(list2[i]) != map.end())
            {
                if (i + map[list2[i]] < mi)
                {
                    res.clear();
                    res.push_back(list2[i]);
                    mi = i + map[list2[i]];
                }
                else if (i + map[list2[i]] == mi)
                {
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};