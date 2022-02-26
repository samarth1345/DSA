#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<numeric>
using namespace std;
int dp[1000][1000];
int help(vector<int> arr, int n, int sum)
{
    if (n == 0)
    {
        // this is a important case which i was missing, in this we have to take care
        // if sum==0 and arr[n] is alse 0, we have two choices there which can get us
        // required result.
        if (sum == 0 && arr[0] == 0)
            return 2;
        if (sum == 0 || arr[0] == sum)
            return 1;
        return 0;
    }
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (arr[n] <= sum)
    {
        return dp[n][sum] = (help(arr, n - 1, sum - arr[n]) + help(arr, n - 1, sum));
    }
    return dp[n][sum] = help(arr, n - 1, sum);
}
// this is same as perfect sum, we find sum by mathematical calculation
// i.e sum(subset1)-sum(subset2)=diff
//     sum(subset1)+sum(subset2)=totalsum
//     2(sum(subset1))=(diff+totalsum)
int findTargetSumWays(vector<int> &nums, int target)
{
    memset(dp, -1, sizeof(dp));
    int total_sum = accumulate(nums.begin(), nums.end(), 0);
    if (total_sum < target || (total_sum + target) % 2 != 0)
        return 0;
    int sum = (target + total_sum) / 2;
    return help(nums, nums.size() - 1, sum);
}