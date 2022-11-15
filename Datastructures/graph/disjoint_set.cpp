#include <bits/stdc++.h>
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
int main()
{
    disjoint_set *dsu = new disjoint_set(8);
    dsu->union_by_size(1, 2);
    dsu->union_by_size(2, 3);
    dsu->union_by_size(4, 5);
    dsu->union_by_size(6, 7);
    dsu->union_by_size(5, 6);
    dsu->union_by_size(3, 7);
    cout << dsu->find_Ultimate_parent(4);
}