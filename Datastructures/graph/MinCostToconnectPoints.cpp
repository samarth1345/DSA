#include <bits/stdc++.h>
using namespace std;
//this is same as making a minimum spanning tree
int minCostConnectPoints(vector<vector<int>> &points)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    unordered_map<int, bool> map;
    int total = points.size(), cost = 0;
    pq.push({0, 0});

    while (total != 0)
    {
        int temp_weight=pq.top().first;
        int temp = pq.top().second;
        pq.pop();
        if (!map[temp])
        {
            cost += temp_weight;
            map[temp] = true;
            total--;
            for (int i = 0; i < points.size(); i++)
            {
                if (!map[i])
                {
                    int weight = abs(points[i][0] - points[temp][0]) + abs(points[i][1] - points[temp][1]);
                    //cout << temp << " " << weight << " " << i << endl;
                    pq.push({weight, i});
                }
            }
        }
    }
    return cost;
}
int main()
{
    vector<vector<int>> points;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        int x, y;
        cin >> x >> y;
        temp.push_back(x);
        temp.push_back(y);
        points.push_back(temp);
    }
    cout << minCostConnectPoints(points);
}