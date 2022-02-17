#include <bits/stdc++.h>
using namespace std;
vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    vector<vector<pair<string, double>>> List;
    unordered_map<string, int> getIndex;
    int size = equations.size();
    for (int i = 0; i < size; i++)
    {
        string string1=equations[i][0],string2=equations[i][1];
        if (getIndex[string1] == 0)
        {
            List.push_back({make_pair(string2, values[i])});
            getIndex[string1] = List.size() - 1;
        }
        else
            List[getIndex[string1]].push_back({string2, values[i]});
        if (getIndex[string2] == 0)
        {
            List.push_back({make_pair(string1, 1/values[i])});
            getIndex[string2] = List.size() - 1;
        }
        else
            List[getIndex[string2]].push_back({string1, 1/values[i]});
    }
    int val_size = values.size();
    vector<double> ans;
    for (int i = 0; i < val_size; i++)
    {
        int index = getIndex[queries[i][0]];
        if (index == 0)
            ans.push_back(-1);
        else
        {
            bool flag = false;
            int size = List[index].size();
            double Ans = 0.0;
            for (int j = 0; j < size; j++)
            {
                Ans += List[index][j].second;
                if (List[index][j].first == queries[i][1])
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                ans.push_back(Ans);
            else
                ans.push_back(-1);
        }
    }
    return ans;
}