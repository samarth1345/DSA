#include <bits/stdc++.h>
using namespace std;
int longestPalindromeSubseq(string s)
{
    string text1 = s, text2 = s;
    reverse(text2.begin(), text2.end());
    int n, m;
    n = m = text1.length();
    int dp[n + 1][n + 1];
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
int minInsertions(string s)
{
    return s.length() - longestPalindromeSubseq(s);
}