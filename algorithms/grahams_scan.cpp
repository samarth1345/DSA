#include<bits/stdc++.h>
using namespace std;
/*IF COLLINEAR POINTS ARE NOT CONSIDERED INSIDE CONVEX HULL*/
static bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
bool clockwise(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    int ax = a.first, ay = a.second, bx = b.first, by = b.second, cx = c.first, cy = c.second;
    return ax * (cy - by) + bx * (ay - cy) + cx * (by - ay) > 0;
}
bool anticlockwise(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    int ax = a.first, ay = a.second, bx = b.first, by = b.second, cx = c.first, cy = c.second;
    return ax * (cy - by) + bx * (ay - cy) + cx * (by - ay) < 0;
}
bool collinear(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    int ax = a.first, ay = a.second, bx = b.first, by = b.second, cx = c.first, cy = c.second;
    return ax * (cy - by) + bx * (ay - cy) + cx * (by - ay) == 0;
}
vector<pair<int, int>> grahams_scan(vector<pair<int, int>> points)
{
    //IF COLLINEAR POINTS ARE CONSIDERED UN-COMMENT LINES 67-72
    int n = points.size();
    if (n < 3)
        return points;
    sort(points.begin(), points.end(), comp);
    vector<pair<int, int>> up, down, middle;
    up.push_back(points[0]);
    down.push_back(points[0]);
    for (int i = 1; i < n; i++){
        if (i == n - 1)
        {
            while (up.size() >= 2 && anticlockwise(up[up.size() - 2], up[up.size() - 1], points[i]))
            {
                up.pop_back();
            }
            while (down.size() >= 2 && clockwise(down[down.size() - 2], down[down.size() - 1], points[i]))
                down.pop_back();
            up.push_back(points[i]);
        }
        else if (clockwise(points[0], points[i], points[n - 1]))
        {
            while (up.size() >= 2 && anticlockwise(up[up.size() - 2], up[up.size() - 1], points[i]))
                up.pop_back();
            up.push_back(points[i]);
        }
        else if (anticlockwise(points[0], points[i], points[n - 1]))
        {
            while (down.size() >= 2 && clockwise(down[down.size() - 2], down[down.size() - 1], points[i]))
                down.pop_back();
            down.push_back(points[i]);
        }
        else
            middle.push_back(points[i]);
    }
    points.clear();
    for (auto i : up)
        points.push_back(i);
    for (auto i : down)
        points.push_back(i);
    // if ((up.size() == 2 || down.size() == 1))
    // {
    //     while (!middle.empty())
    //         points.push_back(middle.back()), middle.pop_back();
    // }
    sort(points.begin(), points.end());
    points.resize(unique(points.begin(), points.end()) - points.begin());
    return points;
}
/*************************************************************************************/
