#include <bits/stdc++.h>
#include "graph_list.h"
using namespace std;
//logic: In bipartite graph if there is a cycle then it has
//even number of nodes in it else it is not a bipartite graph 
//so we just traverse and mark colours and if there is a cycle then 
//paths will be crossed,on contradiction of colours it would be having cycle with 
//odd no. of nodes.
void DFS(vector<int> *List, int node, vector<int> &colour, int prev_colour, bool& flag)
{
    int size = List[node].size();
    for (int i = 0; i < size; i++)
    {
        if (colour[List[node][i]] == -1)
        {
            colour[List[node][i]] = (!prev_colour);
            DFS(List, List[node][i], colour, !prev_colour, flag);
        }
        else if (colour[List[node][i]] != (!prev_colour))
        {
            flag = false;
            return;
        }
    }
}
vector<int> bipartite(vector<int> *List, int vertices)
{
    vector<int> colour(vertices + 1, -1);
    bool flag = true;
    for (int i = 1; i <= vertices; i++)
    {
        if (colour[i] == -1)
        {
            colour[i] = 0;
            DFS(List, i, colour, 0, flag);
            if (!flag)
            {
                cout << "graph is not bipartite\n";
                return {};
            }
        }
    }
    return colour;
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
    vector<int> ans = bipartite(obj->getList(), n);
    for (int i = 1; i < ans.size(); i++)
        cout <<i<< " -> " << ans[i] << endl;
}