#include <bits/stdc++.h>
#include "graph_list_weighted.h"
using namespace std;
void dijkstras(vector<pair<int, int>> *List, int vertices, int source)
{
    vector<int> shortest(vertices, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    shortest[source]=0;
    pq.push({0,source});
    while(!pq.empty())
    {
        pair<int,int> p=pq.top();
        pq.pop();
        for(auto i:List[p.second])
        {
            if(shortest[i.first]>p.first+i.second)
            {
                shortest[i.first]=p.first+i.second;
                pq.push(make_pair(shortest[i.first],i.first));
            }
        }
    }
    for (int i = 0; i < shortest.size(); i++)
        cout << i << "->" << shortest[i] << endl;
}
int main()
{
    int n, m, source;
    cin >> n >> m;
    graph *obj = new graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        obj->input(u, v, w);
    }
    cin>>source;
    dijkstras(obj->getList(),n,source);
}