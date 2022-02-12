#include <bits/stdc++.h>
using namespace std;
void finishing_time(int v, vector<int> *Adj, vector<int> &visited, stack<int> &finish)
{
    for (int i = 0; i < Adj[v].size(); i++)
    {
        if (visited[Adj[v][i]] == 0)
        {
            visited[Adj[v][i]] = 1;
            finishing_time(Adj[v][i], Adj, visited, finish);
            finish.push(Adj[v][i]);
        }
    }
}
void dfs(int v, vector<int> *Adj, vector<int> &visited)
{
    for (int i = 0; i < Adj[v].size(); i++)
    {
        if (visited[Adj[v][i]] == 0)
        {
            visited[Adj[v][i]] = 1;
            dfs(Adj[v][i], Adj, visited);
        }
    }
}
int kosaraju(int V, vector<int> adj[])
{
    // code here
    vector<int> visited(V, 0);
    stack<int> finish;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            finishing_time(i, adj, visited, finish);
            finish.push(i);
        }
    }
    vector<int> adj_2[V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
            adj_2[adj[i][j]].push_back(i);
    }
    vector<int> visited_2(V, 0);
    int count = 0;
    while (!finish.empty())
    {
        if (visited_2[finish.top()] == 0)
        {
            visited_2[finish.top()] = 1;
            dfs(finish.top(), adj_2, visited_2);
            count++;
        }
        finish.pop();
    }
    return count;
}