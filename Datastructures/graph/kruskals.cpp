#include <bits/stdc++.h>
#include "graph_list_weighted.h"
using namespace std;
class disjoint_set
{
    // parent stores the parent of each node before or after compression
    // rank helps in deciding who is going to join other in case of union
    vector<int> parent, rank, size;

public:
    disjoint_set(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i < n + 1; i++)
            parent[i] = i, size[i] = 1;
    }
    int find_Ultimate_parent(int node)
    {
        if (parent[node] == node)
            return node;
        // doing path compression while finding ultimate paret
        return parent[node] = find_Ultimate_parent(parent[node]);
    }
    void union_by_rank(int u, int v)
    {
        int parent_u = find_Ultimate_parent(u);
        int parent_v = find_Ultimate_parent(v);
        if (parent_u == parent_v)
            return;
        if (rank[parent_u] > rank[parent_v])
        {
            parent[parent_v] = parent_u;
        }
        else if (rank[parent_u] < parent[parent_v])
        {
            parent[parent_u] = parent_v;
        }
        else
        {
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }
    }
    // this can give u size of each union,size of each union is stored at its parent
    void union_by_size(int u, int v)
    {
        int parent_u = find_Ultimate_parent(u);
        int parent_v = find_Ultimate_parent(v);
        if (parent_u == parent_v)
            return;
        if (size[parent_u] > size[parent_v])
        {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
        else
        {
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
    }
};
class node
{
public:
    int node1, node2, weight;
};
bool comp(node obj1, node obj2)
{
    return obj1.weight < obj2.weight;
}
void kruskals(node *List, int vertices, int edges)
{
    sort(List, List + edges, comp);
    int cost = 0;
    disjoint_set *set = new disjoint_set(vertices);
    graph *Graph = new graph(vertices);
    for (int i = 0; i < edges; i++)
    {
        if (set->find_Ultimate_parent(List[i].node1) != set->find_Ultimate_parent(List[i].node2))
        {
            set->union_by_size(List[i].node1, List[i].node2);
            cost += List[i].weight;
            Graph->input(List[i].node1, List[i].node2, List[i].weight);
        }
    }
    cout << "Cost=" << cost << endl;
    Graph->print();
}
int main()
{
    int n, m;
    cin >> n >> m;
    node List[m];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        List[i].node1 = u;
        List[i].node2 = v;
        List[i].weight = w;
    }
    kruskals(List, n, m);
}