//detect cycle using kahn's algorithm
//logic:kahn's algorithm only works for DAG so if there is a cycle in
//graph it will not work for that graph,so we will try to run kahn's
//given graph and if there is a cycle it will not work
#include <bits/stdc++.h>
#include "graph_list.h"
using namespace std;
bool detect_cycle(vector<int> *List,int vertices)
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
    int count=0;
    while(!q.empty())
    {
        count++;
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
    if(count==vertices)
    return false;

    return true;
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
    cout<<detect_cycle(obj->getList(),n);
}