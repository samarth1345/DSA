#include <bits/stdc++.h>
using namespace std;
//could have been done iteratively by calculating 1's and their boundaries in less time
//and space
void spread(vector<vector<int>> &grid, vector<vector<int>> &visited, int x, int y, int &peri)
{
    if (grid[x][y] == 0 || visited[x][y] == 1)
        return;
    visited[x][y] = 1;
    if (x == grid.size() - 1)
        peri++;
    if (x == 0)
        peri++;
    if (y == grid[0].size() - 1)
        peri++;
    if (y == 0)
        peri++;
    if (x + 1 < grid.size())
    {
        peri += ((grid[x + 1][y] == 0) ? 1 : 0);
        spread(grid, visited, x + 1, y, peri);
    }
    if (x - 1 >= 0)
    {
        peri += ((grid[x - 1][y] == 0) ? 1 : 0);
        spread(grid, visited, x - 1, y, peri);
    }
    if (y + 1 < grid[x].size())
    {
        peri += ((grid[x][y + 1] == 0) ? 1 : 0);
        spread(grid, visited, x, y + 1, peri);
    }
    if (y - 1 >= 0)
    {
        peri += ((grid[x][y - 1] == 0) ? 1 : 0);
        spread(grid, visited, x, y - 1, peri);
    }
}
int islandPerimeter(vector<vector<int>> &grid)
{
    vector<vector<int>> visited;
    int peri = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        vector<int> temp(grid[i].size(), 0);
        visited.push_back(temp);
    }
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                spread(grid, visited, i, j, peri);
                break;
            }
        }
    }
    return peri;
}