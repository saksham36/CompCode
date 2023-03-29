class Solution
{

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        if (prerequisites.size() == 0)
            return true;

        unordered_map<int, vector<int>> dict;
        vector<int> degree(numCourses, 0);
        queue<int> zeroDegree;
        // Making graph
        for (auto &prereq : prerequisites)
        {
            if (dict.count(prereq[1]))
            {
                dict[prereq[1]].push_back(prereq[0]);
            }
            else
            {
                vector<int> tmp{prereq[0]};
                dict[prereq[1]] = tmp;
            }
            degree[prereq[0]]++;
        }
        for (int i = 0; i < degree.size(); i++)
        {
            if (degree[i] == 0)
            {
                zeroDegree.push(i);
                numCourses--;
            }
        }

        while (zeroDegree.size() > 0)
        {
            int n = zeroDegree.front();
            zeroDegree.pop();
            for (int m : dict[n])
            {
                degree[m]--;
                if (degree[m] == 0)
                {
                    zeroDegree.push(m);
                    numCourses--;
                }
            }
        }
        return numCourses == 0;
    }
};