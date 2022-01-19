#include <bits/stdc++.h>
#include "graph_list_weighted.h"
using namespace std;
void prims(vector<pair<int, int>> *List, int vertices)
{
    vector<int> key(vertices, INT_MAX), parent(vertices, -1);
    vector<bool> MST(vertices, false);
    key[0] = 0;
    int s = vertices - 1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    while (s > 0)
    {
        pair<int,int> v=pq.top();
        pq.pop();
        MST[v.second] = true;
        for (auto i : List[v.second])
        {
            if (!MST[i.first] && key[i.first] > i.second)
            {
                parent[i.first] = v.second;
                key[i.first] = i.second;
                pq.push({i.second,i.first});
            }
        }
        s--;
    }
    for(int i=1;i<vertices;i++)
    {
        cout<<"parent of "<<i<<" is "<<parent[i]<<endl;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    graph *obj = new graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        obj->input(u, v, w);
    }
    prims(obj->getList(),n);
}