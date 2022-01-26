#include <bits/stdc++.h>
using namespace std;
//logic:it gives intuition of disjoint set,we ahve to make a union of all the land
//which are connected and after we connect the lands we are left with few islands
//what we will do is we will run two for loops and if there is a land we will
//see all land which are connected to that land in makeunion function,and change its value
//to "0" inplace of "1" so that it ios not counted again.
void makeunion(vector<vector<char>> &grid, int x, int y)
{
    if ((x >= 0) && (x < grid.size()) && (y >= 0) && (y < grid[0].size()))
    {
        if (grid[x][y] == '0')
            return;
        grid[x][y] = '0';
        makeunion(grid, x + 1, y);
        makeunion(grid, x - 1, y);
        makeunion(grid, x, y + 1);
        makeunion(grid, x, y - 1);
    }
}
int numIslands(vector<vector<char>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    int islands = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == '1')
            {
                makeunion(grid, i, j);
                islands++;
            }
        }
    }
    return islands;
}