#include <bits/stdc++.h>
using namespace std;
// bassically this handles negative edges which dijkstras coudld not handle
vector<int> bellman_ford(int n, vector<vector<int>> edges)
{
    // it returns shortest path array and it expects n(no of vertices) and edges vector
    vector<int> shortest(n, INT_MAX);
    shortest[0] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if (shortest[u] != INT_MAX && shortest[v] > shortest[u] + w)
            {
                shortest[v] = shortest[u] + w;
            }
        }
    }
    // if there is a negative cycle it will return empty array
    // this part checks is there is negative cycle
    for (int j = 0; j < edges.size(); j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];
        if (shortest[u] != INT_MAX && shortest[v] > shortest[u] + w)
        {
            return {};
        }
    }
    // if there is no negative cycle it will return shortest path array
    return shortest;
}