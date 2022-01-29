#include <bits/stdc++.h>
using namespace std;
//this is same as previous dfs questions with only change as 
//we need to remember max increasing path from a position (x,y) if it has been 
//traversed before so that if dfs from some position reaches this position it 
//can just return there with value of max inc. path stored already.
int onepath(vector<vector<int>> &matrix, vector<vector<int>> &visited, int x, int y, int to_compare)
{
    if ((x >= 0) && (x < matrix.size()) && (y >= 0) && (y < matrix[0].size()))
    {
        if (matrix[x][y] <= to_compare)
            return 0;
        if (visited[x][y] != -1)
            return visited[x][y];
        int allpaths[4] = {0};
        int temp = matrix[x][y];
        allpaths[0] = onepath(matrix, visited, x + 1, y, temp);
        allpaths[1] = onepath(matrix, visited, x - 1, y, temp);
        allpaths[2] = onepath(matrix, visited, x, y + 1, temp);
        allpaths[3] = onepath(matrix, visited, x, y - 1, temp);
        return visited[x][y] = (1 + *max_element(allpaths, allpaths + 4));
    }
    return 0;
}
int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int row = matrix.size(), col = matrix[0].size();
    vector<vector<int>> visited(row, vector<int>(col, -1));
    int maxi = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            maxi = max(maxi, onepath(matrix, visited, i, j, INT_MIN));
        }
    }
    return maxi;
}