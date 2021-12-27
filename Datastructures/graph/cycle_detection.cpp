#include <bits/stdc++.h>
#include "graph_list.h"
using namespace std;
//logic: the idea is that we will traverse nodes and if we counter a node 
//which is already traversed and it is not the parent of that node, then it
//means that node has been traversed by some other path and two paths meeting 
//at a single node means there is a cycle.
bool detect_cycle(vector<int> *List,int vertices)
{
    vector<int> visited(vertices+1);
    queue<pair<int,int>> q;
    for (int i = 1; i <= vertices; i++)
    {
        if (!visited[i])
        {
            visited[i]=1;
            q.push({i,-1});
            while (!q.empty())
            {
                int t=q.front().first,p=q.front().second;
                q.pop();
                for(int j=0;j<List[t].size();j++)
                {
                    if (!visited[List[t][j]])
                    {
                        visited[List[t][j]]=1;
                        q.push({List[t][j],t});
                    }
                    //this is part which will tell if there is a cycle
                    else if(List[t][j]!=p)
                        return true;
                }
            }
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
    obj->print();
    vector<int> *List = obj->getList();
    cout<<detect_cycle(List,n);
}