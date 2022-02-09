#include <bits/stdc++.h>
using namespace std;
//this is nearly same as topo sort procedure,graph is indirected so will
//assume it is every edge as bireactional and mark degree for both
//the vertices,in burte force for this problem we would have to 
//travel from root to leaf to optimise this we are traversing from 
//leaf nodes and go level by level.To go level by level we will just use size of queue
//at start and traverse through them and keep on going.
vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    vector<int> degree(n, 0);
    vector<int> List[n];
    int size = edges.size();
    for (int i = 0; i < size; i++)
    {
        int v1 = edges[i][0], v2 = edges[i][1];
        List[v1].push_back(v2);
        List[v2].push_back(v1);
        degree[v1]++;
        degree[v2]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 1)
        {
            degree[i] = 0;
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int size = q.size();
        ans.clear();
        for (int i = 0; i < size; i++)
        {
            int v = q.front();
            q.pop();
            for (int j = 0; j < List[v].size(); j++)
            {
                degree[List[v][j]]--;
                if (degree[List[v][j]] == 1)
                    q.push(List[v][j]);
            }
            ans.push_back(v);
        }
    }
    if (ans.empty())
    {
        ans.push_back(0);
    }
    return ans;
}