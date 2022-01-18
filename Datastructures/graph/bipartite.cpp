#include <bits/stdc++.h>
#include "graph_list.h"
using namespace std;
//logic: In bipartite graph if there is a cycle then it has
//even number of nodes in it else it is not a bipartite graph 
//so we just traverse and mark colours and if there is a cycle then 
//paths will be crossed,on contradiction of colours it would be having cycle with 
//odd no. of nodes.
vector<int> bipartite(vector<int> *graph, int vertices)
{
    vector<int> colour(vertices + 1, -1);
    queue<pair<int, int>> q;
    for (int i = 1; i <= vertices; i++)
    {
        if (colour[i] == -1)
        {
            q.push({i, 0});
            colour[i] = 0;
            while (!q.empty())
            {
                int temp = q.front().first,prev=q.front().second;
                q.pop();
                for (int i = 0; i < graph[temp].size(); i++)
                {
                    if (colour[graph[temp][i]]==-1)
                    {
                        colour[graph[temp][i]]=(!prev);
                        q.push({graph[temp][i],!prev});
                    }
                    else if(colour[graph[temp][i]]==prev)
                    {
                        cout<<"graph is not bipartite\n";
                        return {};
                    }
                }
            }
        }
    }
    cout<<"0 -> green\n1 -> red\n";
    return colour;
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
    vector<int> *graph=obj->getList();
    vector<int> ans=bipartite(graph,n);
    for(int i=1;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
