class Solution
{
public:
    int find(vector<int> &parent, int x)
    {
        // cout<<"In find: parent["<<x<<"]: "<<parent[x]<<endl;
        if (x == parent[x])
            return x;                        // Node is not connected yet, it's on parent
        parent[x] = find(parent, parent[x]); // Recursively find parent
        return parent[x];
    }
    // void union_func(int x, int y){
    //     // return true;
    // }
    bool union_func(int x, int y, vector<int> &rank, vector<int> &parent)
    {
        int parent_x = find(parent, x);
        int parent_y = find(parent, y);
        // cout<<parent_x<<" "<<parent_y<<endl;
        if (parent_x == parent_y)
            return false; // already in same union
        // cout<<"Rank: "<<rank[parent_x]<<" "<<rank[parent_y]<<endl;
        if (rank[parent_x] >= rank[parent_y])
        {
            rank[parent_x] += rank[parent_y];
            parent[y] = parent_x;
            parent[parent_y] = parent_x;
        }
        else
        {
            rank[parent_y] += rank[parent_x];
            parent[x] = parent_y;
            parent[parent_x] = parent_y;
        }
        // for(auto p: parent)
        //     cout<<p<<" ";
        // cout<<endl;

        // for(auto r: rank)
        //     cout<<r<<" ";
        // cout<<endl;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> parent(n + 1);
        iota(parent.begin(), parent.end(), 0);
        vector<int> rank(n + 1, 1);

        for (auto edge : edges)
        {
            // cout<<x<<endl;
            if (!union_func(edge[0], edge[1], rank, parent))
                return edge;
        }
        return {};
    }
};