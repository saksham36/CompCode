class Solution
{
public:
    int dfs(int current, map<int, vector<int> > &children_map, vector<int> &time, vector<int> &informTime)
    {
        if (time[current] != -1)
            return time[current];
        // cout<<"Current: "<<current<<endl;
        if (children_map.count(current) == 0)
        {
            time[current] = 0;
            return 0;
        }
        time[current] = informTime[current];
        int temp = 0;
        for (auto x : children_map[current])
        {
            temp = max(temp, dfs(x, children_map, time, informTime));
        }
        // cout<<"Current: "<<current<<endl;
        time[current] += temp;
        // cout<<"temp: "<<temp<<" Res: "<<time[current]<<endl;
        return time[current];
    }
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        // need to find max sum of informTime from top to bottom
        map<int, vector<int> > children_map;
        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
            {
                // cout<<manager[i]<<endl;
                children_map[manager[i]].push_back(i);
            }
        }
        // for(auto x: children_map)
        //     cout<<x.first<<endl;
        vector<int> time(n, -1); //vector representing the time it
        return dfs(headID, children_map, time, informTime);
    }
};