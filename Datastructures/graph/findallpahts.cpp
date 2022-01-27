#include <bits/stdc++.h>
using namespace std;
//find all paths from 0 to n-1 vertice in a graph
//use dfs.
void help(vector<vector<int>> &graph, int start, vector<int> psf, vector<vector<int>> &ans)
{
    psf.push_back(start);
    if (start == graph.size() - 1)
    {
        ans.push_back(psf);
        return;
    }
    for (int i = 0; i < graph[start].size(); i++)
    {
        help(graph, graph[start][i], psf, ans);
    }
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<vector<int>> ans;
    vector<int> psf;
    help(graph, 0, psf, ans);
    return ans;
}