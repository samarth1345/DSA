#include <bits/stdc++.h>
using namespace std;
//we will use dfs technique to trace adjacent land to make
//an island
int spreadAcrossArea(vector<vector<int>> &grid, int x, int y)
{
    if ((x >= 0) && (x < grid.size()) && (y >= 0) && (y < grid[0].size()))
    {
        if (grid[x][y] == 0)
        {
            return 0;
        }
        grid[x][y] = 0;
        return 1 +
               spreadAcrossArea(grid, x + 1, y) +
               spreadAcrossArea(grid, x - 1, y) +
               spreadAcrossArea(grid, x, y + 1) +
               spreadAcrossArea(grid, x, y - 1);
    }
    return 0;
}
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int row = grid.size(), col = grid[0].size();
    int max_island = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 1)
                max_island = max(max_island, spreadAcrossArea(grid, i, j));
        }
    }
    return max_island == INT_MIN ? 0 : max_island;
}
