#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
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