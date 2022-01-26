//only for DAG
#include <bits/stdc++.h>
#include "graph_list.h"
using namespace std;
void dfs(stack<int> &final_ans, vector<int> *List, vector<int> &visited, int t)
{
    for (int j = 0; j < List[t].size(); j++)
    {
        if (!visited[List[t][j]])
        {
            visited[List[t][j]] = 1;
            dfs(final_ans, List, visited, List[t][j]);
            final_ans.push(List[t][j]);
        }
    }
}
vector<int> top_sort(vector<int> *List, int vertices)
{
    vector<int> visited(vertices), ans;
    stack<int> final_ans;
    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            dfs(final_ans, List, visited, i);
            final_ans.push(i);
        }
    }
    while (!final_ans.empty())
    {
        ans.push_back(final_ans.top());
        final_ans.pop();
    }
    return ans;
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
        obj->input_directed(u, v);
    }
    //obj->print();
    vector<int> ans = top_sort(obj->getList(), n);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}