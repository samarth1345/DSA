#include<bits/stdc++.h>
using namespace std;
// memoization approach
int dp[101][10001];
bool help(int N, int arr[], int sum)
{
    if (sum == 0)
        return true;
    if (N == 0 || sum < 0)
        return false;
    if (dp[N - 1][sum] != -1)
        return dp[N - 1][sum];
    return dp[N - 1][sum] = (help(N - 1, arr, sum - arr[N - 1]) | help(N - 1, arr, sum));
}
bool isSubsetSum(int N, int arr[], int sum)
{
    // code here
    memset(dp, -1, sizeof(dp));
    return help(N, arr, sum);
}
// bottom up approach
bool dp[101][10001];
bool isSubsetSum(int N, int arr[], int sum)
{
    // code here
    for (int i = 0; i <= N; i++)
        dp[i][0] = true;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j - arr[i - 1] >= 0)
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] | dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[N][sum];
}