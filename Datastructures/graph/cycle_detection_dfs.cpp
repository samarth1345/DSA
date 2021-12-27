#include <bits/stdc++.h>
#include "graph_list.h"
using namespace std;
//this is same as bfs approach,only differnce is we have to pass 
//parent node in parameters as we don't have idea about parent node
//in DFS_help function. 
bool DFS_help(vector<int> *List,vector<int> &visited,int t,int parent)
{
    bool ans=false;
    visited[t]=1;
    for (int j = 0; j < List[t].size(); j++)
    {
        if(!visited[List[t][j]])
        {
            visited[List[t][j]]=1;
            ans=ans | DFS_help(List,visited,List[t][j],t);
        }
        else if(List[t][j]!=parent)
            return true;
    }
    return ans;
}
bool check_cycle(vector<int> *List, int vertices)
{
    vector<int> visited(vertices + 1);
    for (int i = 1; i <= vertices; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            bool ans=DFS_help(List,visited,i,-1);
            if(ans)
                return true;
        }
    }
    return false;
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
    obj->print();
    cout<<check_cycle(List, n);
}