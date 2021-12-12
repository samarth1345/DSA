#include <bits/stdc++.h>
using namespace std;
float calc(int a, int b)
{
    return sqrt(a*a+b*b);
}
//just make heap based on their distance from origin and maintain
//k sized heap 
void kClosest(vector<vector<int>> &points, int k)
{
    priority_queue<pair<float, pair<int, int>>> pq;
    int row = points.size();
    for (int i = 0; i < row; i++)
    {
        int a = points[i][0], b = points[i][1];
        float temp = calc(a, b);
        pair<float, pair<int, int>> t;
        t.first = temp;
        t.second.first = a;
        t.second.second = b;
        if (pq.size() < k)
        {
            pq.push(t);
        }
        else if (!pq.empty() && pq.top().first > temp)
        {
            pq.pop();
            pq.push(t);
        }
    }
    while (!pq.empty())
    {
        cout<<pq.top().first<<" "<<pq.top().second.first<<" "<<pq.top().second.second<<endl;
        pq.pop();
    }
}
int main()
{
    vector<vector<int>> points;
    int size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        vector<int> temp;
        int a,b;
        cin>>a>>b;
        temp.push_back(a); temp.push_back(b);
        points.push_back(temp);
    }
    int k;
    cin>>k;
    kClosest(points,k);
}