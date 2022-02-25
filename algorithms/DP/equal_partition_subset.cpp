#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
using namespace std;
int dp[201][10001];
bool isSubsetSum(int N, vector<int> arr, int sum)
{
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
bool canPartition(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1)
        return false;
    memset(dp, -1, sizeof(dp));
    return isSubsetSum(nums.size(), nums, sum / 2);
}