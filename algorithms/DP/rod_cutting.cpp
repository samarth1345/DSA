#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
//first example of unbounded knapsack 
int solve(int price[], int n, int l)
{
    if (n < 1)
        return 0;
    if (dp[n][l] != -1)
        return dp[n][l];
    if (n <= l)
        return dp[n][l] = max(price[n - 1] + solve(price, n, l - n), solve(price, n - 1, l));
    return solve(price, n - 1, l);
}
int cutRod(int price[], int n)
{
    // code here
    memset(dp, -1, sizeof(dp));
    return solve(price, n, n);
}