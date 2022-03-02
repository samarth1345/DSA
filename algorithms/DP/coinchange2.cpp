#include <bits/stdc++.h>
using namespace std;
int dp[20][10000];
int solve(vector<int> &coins, int amount, int n)
{
    if (amount == 0)
        return 0;
    if (n < 1)
        return INT_MAX - 1;
    //this is a special case in which we have to handle when n==1
    //considering coins to be sorted coins[0] to be smallest,if it cannot divide
    //amount it cannot add upto amount with any number of coins.
    if (n == 1)
    {
        if (amount % coins[0] == 0)
            return amount / coins[0];
        return INT_MAX - 1;
    }
    if (dp[n][amount] != -1)
        return dp[n][amount];
    if (amount >= coins[n - 1])
        return dp[n][amount] = min(1 + solve(coins, amount - coins[n - 1], n), solve(coins, amount, n - 1));
    return dp[n][amount] = solve(coins, amount, n - 1);
}
int coinChange(vector<int> &coins, int amount)
{
    memset(dp, -1, sizeof(dp));
    int ans = solve(coins, amount, coins.size());
    return ans > INT_MAX - 10000 ? -1 : ans;
}