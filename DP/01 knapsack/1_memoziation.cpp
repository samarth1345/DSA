//memoziation approach for 01 knapsack
#include <bits/stdc++.h>
using namespace std;
#define maximum 100
//this is a 2d array to store the values of knapsack calls and for using in future instead of making a recursive call again
static int dp[maximum][maximum] ;
int knapsack(int wt[], int val[], int twt, int n)
{
    if (n == 0 || twt == 0)
    {
        return 0;
    }
    if (dp[twt][n-1] != -1)      //if there is a value in dp instead of -1 we are going to return that value instead of making a call
    {
        return dp[twt][n-1];
    }
    else if (wt[n - 1] <= twt)
    {
        //we are also storing value in dp for future refernce
        return dp[twt][n-1] = max(val[n - 1] + knapsack(wt, val, twt - wt[n - 1], n - 1), knapsack(wt, val, twt, n - 1));
    }
    else
    {
        return dp[twt][n-1] = knapsack(wt, val, twt, n - 1);
    }
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int twt, n;
    cin >> n >> twt;
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }
    cout << knapsack(wt, val, twt, n);
    return 0;
}
