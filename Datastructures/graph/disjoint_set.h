#include <bits/stdc++.h>
using namespace std;
class disjoint_set
{
    int no_of_vertices;
    vector<int> parent, rank;
public:
    disjoint_set(int n)
    {
        no_of_vertices = n;
        for (int i = 0; i <= n; i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    int find_parent(int node)
    {
        int temp = node;
        while (parent[temp] != temp)
        {
            temp = parent[temp];
        }
        if (parent[node] != temp)
            parent[node] = temp;
        return temp;
    }
    void Union(int node1, int node2)
    {
        int parent1, parent2;
        parent1 = find_parent(node1);
        parent2 = find_parent(node2);
        if (rank[parent1] >= rank[parent2])
        {
            rank[parent1]++;
            parent[parent2]=parent1;
        }
        else
        {
            rank[parent2]++;
            parent[parent1]=parent2;
        }
    }
    vector<int> GetParentList()
    {
        return parent;
    }
};