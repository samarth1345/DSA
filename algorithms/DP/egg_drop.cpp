#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <numeric>
using namespace std;
int dp[101][10001];
int help(int k, int n)
{
    if (k == 0)
        return INT_MAX;
    if (n == 1 || n == 0 || k == 1)
        return n;
    if (dp[k][n] != -1)
        return dp[k][n];
    int mn = INT_MAX, start = 1, end = n, mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        int temp1, temp2;
        temp1 = help(k - 1, mid - 1);
        temp2 = help(k, n - mid);
        int temp = 1 + max(temp1, temp2);
        mn = min(mn, temp);
        if (temp1 > temp2)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return dp[k][n] = mn;
}
int superEggDrop(int k, int n)
{
    memset(dp, -1, sizeof(dp));
    return help(k, n);
}