#include<bits/stdc++.h>
#include"graph_list_weighted.h"
#include"disjoint_set.h"
using namespace std;
//logic: we have used disjoint set for making acyclic shortest spanning
//tree 
class node{
    public:
    int node1,node2,weight;
};
bool comp(node obj1,node obj2)
{
    return obj1.weight < obj2.weight;
}
void kruskals(node *List,int vertices,int edges)
{
    sort(List,List+edges,comp);
    int cost=0;
    disjoint_set *set=new disjoint_set(vertices);
    graph *Graph=new graph(vertices);
    for(int i=0;i<edges;i++)
    {
        if(set->find_parent(List[i].node1) != set->find_parent(List[i].node2))
        {
            set->Union(List[i].node1,List[i].node2);
            cost+=List[i].weight;
            Graph->input(List[i].node1,List[i].node2,List[i].weight);
        }
    }
    cout<<"Cost="<<cost<<endl;
    Graph->print();
}
int main()
{
    int n,m;
    cin>>n>>m;
    node List[m];
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        List[i].node1=u;
        List[i].node2=v;
        List[i].weight=w;
    }
    kruskals(List,n,m);
}