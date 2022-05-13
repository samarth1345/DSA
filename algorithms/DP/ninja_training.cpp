#include <bits/stdc++.h>
using namespace std;
int dp[100001][3];
int solve(int n, vector<vector<int>> &points, int j)
{
    if (n < 1)
        return 0;
    if (dp[n][j] != -1)
        return dp[n][j];
    int mx = -1;
    for (int i = 0; i < 3; i++)
    {
        if (i != j)
            mx = max(mx, points[n - 1][i] + solve(n - 1, points, i));
    }
    return dp[n][j] = mx;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    memset(dp, -1, sizeof(dp));
    return solve(n, points, -1);
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> points[i][j];
        }
    }
    cout << ninjaTraining(n, points);
}