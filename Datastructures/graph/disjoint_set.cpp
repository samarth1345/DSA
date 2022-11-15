#include <bits/stdc++.h>
using namespace std;
class disjoint_set
{
    // parent stores the parent of each node before or after compression
    // rank helps in deciding who is going to join other in case of union
public:
    vector<int> parent, rank;
    disjoint_set(int n){
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 0; i < n + 1; i++)
            parent[i] = i;
    }
    int find_Ultimate_parent(int node){
        if (parent[node] == node)
            return node;
        // doing path compression while finding ultimate paret
        return parent[node] = find_Ultimate_parent(parent[node]);
    }
    void union_by_rank(int u, int v){
        // cout<<u<<" "<<v<<endl;
        int parent_u = find_Ultimate_parent(u);
        int parent_v = find_Ultimate_parent(v);
        if (parent_u == parent_v)
            return;
        if (rank[parent_u] > rank[parent_v]){
            parent[parent_v] = parent_u;
        }
        else if (rank[parent_u] < parent[parent_v]){
            parent[parent_u] = parent_v;
        }
        else{
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }
    }
};
int main()
{
    disjoint_set *dsu = new disjoint_set(8);
    // cout<<"heelo"<<endl;
    dsu->union_by_rank(1, 2);
    dsu->union_by_rank(2, 3);
    dsu->union_by_rank(4, 5);
    dsu->union_by_rank(6, 7);
    dsu->union_by_rank(5, 6);
    dsu->union_by_rank(3, 7);
    cout << dsu->find_Ultimate_parent(4);
}