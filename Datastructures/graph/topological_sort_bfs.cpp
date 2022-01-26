//kahn's algorithm
//only for DAG
#include <bits/stdc++.h>
#include "graph_list.h"
using namespace std;
void kahns(vector<int> *List,int vertices)
{
    vector<int> indegree(vertices);
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<List[i].size();j++)
        {
            indegree[List[i][j]]++;
        }
    }
    queue<int> q;
    for(int i=0;i<vertices;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        int temp=q.front();
        q.pop();
        for(int i=0;i<List[temp].size();i++)
        {
            indegree[List[temp][i]]--;
            if(indegree[List[temp][i]]==0)
                q.push(List[temp][i]);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    graph *obj=new graph(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        obj->input_directed(u,v);
    }
    kahns(obj->getList(),n);
}