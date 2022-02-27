#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <numeric>
using namespace std;
long long cancomplete(vector<int> &time, long long totalTrips, long long timegiven)
{
    long long int count = 0;
    for (int i = 0; i < time.size(); i++)
    {
        count += (timegiven / time[i]);
    }
    return count;
}
long long minimumTime(vector<int> &time, int totalTrips)
{
    long long start = 1, end = 1e14, mid, ans = 0;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (cancomplete(time, totalTrips, mid) >= totalTrips)
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ans;
}