#include <bits/stdc++.h>
using namespace std;
int dp[1000][5001];
//find all ways of making amount with given coins 
int solve(vector<int> &coins, int amount, int n)
{
    if (amount == 0)
        return 1;
    if (n < 1)
        return 0;
    if (dp[n][amount] != -1)
        return dp[n][amount];
    if (amount >= coins[n - 1])
        return dp[n][amount] = solve(coins, amount - coins[n - 1], n) + solve(coins, amount, n - 1);
    return dp[n][amount] = solve(coins, amount, n - 1);
}
int change(int amount, vector<int> &coins)
{
    memset(dp, -1, sizeof(dp));
    return solve(coins, amount, coins.size());
}