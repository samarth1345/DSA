#include <bits/stdc++.h>
using namespace std;
long long minimumRemoval(vector<int> &beans)
{
    long long sum = accumulate(beans.begin(), beans.end(), 0L), mini = LLONG_MAX, size = beans.size();
    sort(beans.begin(), beans.end());
    for (int i = 0; i < size; i++)
    {
        mini = min(mini, (sum - (size - i) * beans[i]));
    }
    return mini;
}