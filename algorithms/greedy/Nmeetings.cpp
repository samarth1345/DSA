#include <bits/stdc++.h>
using namespace std;
static bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    vector<pair<int, int>> list;
    for (int i = 0; i < n; i++)
    {
        list.push_back({start[i], end[i]});
    }
    sort(list.begin(), list.end(), comp);
    int count = 1, ending = list[0].second;
    for (int i = 1; i < n; i++)
    {
        if (list[i].first > ending)
        {
            count++;
            ending = list[i].second;
        }
    }
    return count;
}