#include <bits/stdc++.h>
using namespace std;
#include "graph_list.h"
using namespace std;
void BFS(vector<int> *List, int vertices)
{
    vector<int> visited(vertices+1);
    queue<int > q;
    for (int i = 1; i <= vertices; i++)
    {
        if (!visited[i])
        {
            cout<<i<<" ";
            visited[i]=1;
            q.push(i);
            while (!q.empty())
            {
                int t=q.front();
                q.pop();
                for(int j=0;j<List[t].size();j++)
                {
                    if (!visited[List[t][j]])
                    {
                        cout<<List[t][j]<<" ";
                        visited[List[t][j]]=1;
                        q.push(List[t][j]);
                    }
                }
            }
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
    vector<int> *List = obj->getList();
    BFS(List, n);
}