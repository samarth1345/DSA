#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int solve(vector<int> arr, int start, int end)
{
    int mn = INT_MAX;
    if (start >= end)
        return 0;
    if (dp[start][end] != -1)
        return dp[start][end];
    for (int i = start; i < end; i++)
    {
        int temp1, temp2, temp;
        temp1 = solve(arr, start, i);
        temp2 = solve(arr, i + 1, end);
        temp = temp1 + temp2 + (arr[start - 1] * arr[i] * arr[end]);
        mn = min(mn, temp);
    }
    return dp[start][end] = mn;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(arr, 1, n - 1) << endl;
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 1; j < arr.size(); j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}