#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
//memoization approach
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