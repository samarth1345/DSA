#include<bits/stdc++.h>
using namespace std;
//logic:we just had to detect cycle in graph because if there were a cycle
//person would not be able to complete courses as it would lead to deadlock
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> indegree(numCourses, 0), List[numCourses];
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
        for (int i = 0; i < List[temp].size(); i++)
        {
            indegree[List[temp][i]]--;
            if (indegree[List[temp][i]] == 0)
                q.push(List[temp][i]);
        }
    }
    if (count == numCourses)
        return true;
    return false;
}