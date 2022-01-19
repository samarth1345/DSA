#include <bits/stdc++.h>
#include "graph_list_weighted.h"
using namespace std;
//logic:we could have used simple dfs or bfs traversal as we did in
//undirected graph but that includes overhead of travsersing same node again 
//if there is a better path for that node,but for DAG we can use topo sort to remove 
//this overhead.
void dfs(stack<int> &final_ans, vector<pair<int,int>> *List, vector<int> &visited, int t)
{
    for (int j = 0; j < List[t].size(); j++)
    {
        if (!visited[List[t][j].first])
        {
            visited[List[t][j].first] = 1;
            dfs(final_ans, List, visited, List[t][j].first);
            final_ans.push(List[t][j].first);
        }
    }
}
stack<int> top_sort(vector<pair<int,int>> *List, int vertices)
{
    vector<int> visited(vertices), ans;
    stack<int> final_ans;
    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            dfs(final_ans, List, visited, i);
            final_ans.push(i);
        }
    }
    return final_ans;
}
vector<int> shortest_path(vector<pair<int,int>> *List,int vertices,int source)
{
    stack<int> topo=top_sort(List,vertices);
    vector<int> shortest(vertices,INT_MAX);
    shortest[source]=0;
    while(!topo.empty())
    {
        int temp=topo.top();
        topo.pop();
        if(shortest[temp]!=INT_MAX)
        {
            for(auto i:List[temp])
            {
                if(shortest[i.first]>shortest[temp]+i.second)
                shortest[i.first]=shortest[temp]+i.second;
            }
        }
    }
    return shortest;
}
int main()
{
    int n,m,source;
    cin>>n>>m;
    graph *obj=new graph(n);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        obj->input_directed(u,v,w);
    }
    cin>>source;
    vector<int> ans=shortest_path(obj->getList(),n,source);
    for (int i = 0; i < ans.size(); i++)
        cout << i << "->" << ans[i] << endl;
}