#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <numeric>
using namespace std;
//instead of finding how much glass is full just start from topmost 
//glass and keep flowing leftout water downwards and just check how
//much is that glass filled.
double champagneTower(int poured, int query_row, int query_glass)
{
    double dp[101][101];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = (double)poured;
    for (int i = 0; i <= query_row; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (dp[i][j] > 1)
            {
                double left = (dp[i][j] - 1.0) / 2.0;
                dp[i + 1][j] += left;
                dp[i + 1][j + 1] += left;
            }
        }
    }
    // cout<<dp[query_row][query_glass]<<endl;
    return dp[query_row][query_glass] >= 1.0 ? 1.0 : dp[query_row][query_glass];
}