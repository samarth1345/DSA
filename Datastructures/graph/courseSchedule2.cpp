#include <bits/stdc++.h>
using namespace std;
//same as course schedule1 we just need to return order of courses taken
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> indegree(numCourses, 0), List[numCourses], ans;
    int size = prerequisites.size();
    for (int i = 0; i < size; i++)
    {
        indegree[prerequisites[i][1]]++;
        List[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    int count = 0;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        count++;
        ans.push_back(temp);
        for (int i = 0; i < List[temp].size(); i++)
        {
            indegree[List[temp][i]]--;
            if (indegree[List[temp][i]] == 0)
                q.push(List[temp][i]);
        }
    }
    reverse(ans.begin(), ans.end());
    if (count == numCourses)
        return ans;
    return {};
}