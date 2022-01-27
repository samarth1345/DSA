#include <bits/stdc++.h>
#include "graph_list_weighted.h"
using namespace std;
//logic:only difference from simple dijkstras ago is that we have to also
//take care of stops that flight takes. This is can be optimised with DP.
void dijkstras(vector<pair<int, int>> *List, int vertices, int source, int dest, int k)
{
    vector<int> shortest(vertices, INT_MAX),stops(vertices);
    priority_queue<pair<int, pair<int,int>>> pq;
    shortest[source] = 0;
    stops[source]=0;
    pq.push({0, {source,-1}});
    while (!pq.empty())
    {
        pair<int, pair<int,int>> p = pq.top();
        pq.pop();
        for (auto i : List[p.second.first])
        {
            if ((shortest[i.first] > p.first + i.second)&&(p.second.second+1<=k))
            {
                shortest[i.first] = p.first + i.second;
                stops[i.first]=p.second.second+1;
                pq.push({shortest[i.first], {i.first,p.second.second+1}});
            }
        }
    }
    for (int i = 0; i < shortest.size(); i++)
        cout << i << "->" << shortest[i] << " stops :"<<stops[i]<<endl;
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
        obj->input_directed(u, v, w);
    }
    dijkstras(obj->getList(),n,0,2,2);
}