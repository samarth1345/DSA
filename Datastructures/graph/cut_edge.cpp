#include <bits/stdc++.h>
#include "graph_list.h"
using namespace std;
vector<int> min_time(20, -1);
vector<int> taken_time(20, -1);
// algorithm to find cut edge in a graph
void DFS(vector<int> *List, vector<int> &visited, int t, int parent, int &Time)
{
    visited[t] = 1;
    taken_time[t] = min_time[t] = Time++;
    for (int j = 0; j < List[t].size(); j++)
    {
        if (List[t][j] == parent)
            continue;
        if (!visited[List[t][j]])
        {
            DFS(List, visited, List[t][j], t, Time);
            min_time[t] = min(min_time[t], min_time[List[t][j]]);
            if (min_time[List[t][j]] > taken_time[t])
            {
                cout << t << " " << List[t][j] << endl;
            }
        }
        else
        {
            min_time[t] = min(min_time[t], taken_time[List[t][j]]);
        }
    }
}
void cut_edges(vector<int> *List, int vertices)
{
    vector<int> visited(vertices + 1);
    int Time = 0;
    for (int i = 1; i <= vertices; i++)
    {
        if (!visited[i])
        {
            DFS(List, visited, i, -1, Time);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    graph *obj = new graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        obj->input(u, v);
    }
    cut_edges(obj->getList(), n);
}