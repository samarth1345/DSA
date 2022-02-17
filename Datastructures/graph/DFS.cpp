#include <bits/stdc++.h>
using namespace std;
#include "graph_list.h"
using namespace std;
double dodfs(vector<vector<pair<string, double>>> List, unordered_map<string, int> getIndex, vector<int> &visited, string start, string end, int index)
{
    if (start == end)
        return 1;
    for (int i = 0; i < List[index].size(); i++)
    {
        int temp_index = getIndex[List[index][i].first];
        if (visited[temp_index] == 0)
        {
            string newstart = List[index][i].first;
            visited[temp_index] = 1;
            double ans = dodfs(List, getIndex, visited, newstart, end, temp_index);
            if (ans != -1)
                return ans * List[index][i].second;
        }
    }
    return -1;
}
double dfs(vector<vector<pair<string, double>>> List, unordered_map<string, int> getIndex, string start, string end, int index)
{
    if (start == end && getIndex.find(start) != getIndex.end())
        return 1;
    vector<int> visited(List.size(), 0);
    visited[index] = 1;
    for (int i = 0; i < List[index].size(); i++)
    {
        int temp_index = getIndex[List[index][i].first];
        if (visited[temp_index] == 0)
        {
            string newstart = List[index][i].first;
            double ans = dodfs(List, getIndex, visited, newstart, end, temp_index);
            visited[temp_index] = 1;
            if (ans != -1)
                return ans * List[index][i].second;
        }
    }
    return -1;
}
vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    vector<vector<pair<string, double>>> List;
    unordered_map<string, int> getIndex;
    int size = equations.size();
    for (int i = 0; i < size; i++)
    {
        if (getIndex.find(equations[i][0]) == getIndex.end())
        {
            List.push_back({make_pair(equations[i][1], values[i])});
            getIndex[equations[i][0]] = List.size() - 1;
        }
        else
            List[getIndex[equations[i][0]]].push_back({equations[i][1], values[i]});
        if (getIndex.find(equations[i][1]) == getIndex.end())
        {
            List.push_back({make_pair(equations[i][0], (1 / values[i]))});
            getIndex[equations[i][1]] = List.size() - 1;
        }
        else
            List[getIndex[equations[i][1]]].push_back({equations[i][0], (1 / values[i])});
    }
    int val_size = queries.size();
    vector<double> ans;
    for (int i = 0; i < val_size; i++)
    {
        if (getIndex.find(queries[i][0]) == getIndex.end())
            ans.push_back(-1);
        else
            ans.push_back(dfs(List, getIndex, queries[i][0], queries[i][1], getIndex[queries[i][0]]));
    }
    return ans;
}