//this is same as bfs with slight modifiaction,shortest path vector comes in
//to store the shortest path of node from source
#include <bits/stdc++.h>
#include "graph_list.h"
using namespace std;
vector<int> shortest_path(vector<int> *List, int vertices, int source)
{
    vector<int> shortest(vertices, INT_MAX);
    queue<int> q;
    q.push(source);
    shortest[source] = 0;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int i = 0; i < List[temp].size(); i++)
        {
            if (shortest[List[temp][i]] > shortest[temp] + 1)
            {
                shortest[List[temp][i]] = shortest[temp] + 1;
                q.push(List[temp][i]);
            }
        }
    }
    return shortest;
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
    vector<int> ans = shortest_path(obj->getList(), n, 0);
    for (int i = 0; i < ans.size(); i++)
        cout << i << "->" << ans[i] << endl;
}