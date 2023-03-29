class Solution
{
private:
    void dfs(vector<vector<char>> &grid, int r, int c)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r - 1][c] == '1')
            dfs(grid, r - 1, c);
        if (r + 1 < rows && grid[r + 1][c] == '1')
            dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c - 1] == '1')
            dfs(grid, r, c - 1);
        if (c + 1 < cols && grid[r][c + 1] == '1')
            dfs(grid, r, c + 1);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.size() == 0)
            return 0;

        int num_islands = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    cout << "i: " << i << " j: " << j << endl;
                    num_islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return num_islands;
    }
};