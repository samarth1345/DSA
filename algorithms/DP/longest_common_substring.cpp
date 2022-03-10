#include <bits/stdc++.h>
using namespace std;
int longestCommonSubstr(string S1, string S2, int n, int m)
{
    int dp[1001][1001], g = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                //we can have a longer commom substring which is not 
                //attached with last character so we have to keep checking 
                //for max.
                g = max(g, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return g;
}
int main()
{
    int n, m;
    string S1, S2;
    cin >> n >> m;
    cin >> S1 >> S2;
    cout << longestCommonSubstr(S1, S2, n, m);
}