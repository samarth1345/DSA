#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
//top down approach
int help(string &text1, string &text2, int len1, int len2)
{
    if (len1 == -1 || len2 == -1)
        return 0;
    if (dp[len1][len2] != -1)
        return dp[len1][len2];
    if (text1[len1] == text2[len2])
    {
        return dp[len1][len2] = 1 + help(text1, text2, len1 - 1, len2 - 1);
    }
    int perm1 = help(text1, text2, len1, len2 - 1);
    int perm2 = help(text1, text2, len1 - 1, len2);
    return dp[len1][len2] = max(perm1, perm2);
}
int longestCommonSubsequence(string text1, string text2)
{
    memset(dp, -1, sizeof(dp));
    return help(text1, text2, text1.length() - 1, text2.length() - 1);
}
//botoom up approach
int longestCommonSubsequence(string text1, string text2)
{
    int dp[1001][1001];
    int n = text1.length(), m = text2.length();
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}