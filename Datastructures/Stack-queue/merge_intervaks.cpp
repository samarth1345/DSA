#include <bits/stdc++.h>
using namespace std;
bool sortcol(const vector<int> &v1, const vector<int> &v2)
{
    return v1[0] < v2[0];
}
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), sortcol);
    stack<pair<int, int>> Stack;
    vector<vector<int>> ans;
    int size = intervals.size();
    for (int i = 0; i < size; i++)
    {
        Stack.push({intervals[i][0], intervals[i][1]});
        if (Stack.size() > 1)
        {
            int A, B;
            A = Stack.top().first;
            B = Stack.top().second;
            Stack.pop();
            if (A <= Stack.top().second)
            {
                int C=Stack.top().first;
                Stack.pop();
                Stack.push({C,B});
            }
            else if (A == Stack.top().first)
            {
                int C=max(Stack.top().second,B);
                Stack.pop();
                Stack.push({A,C});
            }
            else
            {
                Stack.push({A,B});
            }
        }
    }
    while(Stack.size())
    {
        ans.push_back({Stack.top().first,Stack.top().second});
        Stack.pop();
    }
    return ans;
}
int main()
{
    vector<vector<int>> vec = {{1, 4}, {1,5}};
    vector<vector<int>> ans = merge(vec);
    int size = ans.size();
    int i = 0;
    while (i < size)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
        i++;
    }
}