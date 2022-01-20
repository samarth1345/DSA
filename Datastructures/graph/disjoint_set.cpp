#include <bits/stdc++.h>
#include "graph_list.h"
#define vi vector<int>
#define vipi vector<pair<int, int>>
#define pi pair<int, int>
using namespace std;
class disjoint_set
{
    int no_of_vertices;
    vi parent, rank;
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
            parent[parent1]=parent1;
        }
    }
};
int main()
{
    int n;
    cin>>n;
    disjoint_set *set=new disjoint_set(n);
    set->Union(1,2);
    set->Union(2,3);
    set->Union(4,5);
    set->Union(6,7);
    set->Union(5,6);
    set->Union(3,7);
    cout<<set->find_parent(5);
}