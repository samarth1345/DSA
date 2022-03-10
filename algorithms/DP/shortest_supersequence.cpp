#include <bits/stdc++.h>
using namespace std;
// this is just a variation of longest common subsequence
// only thing was to make the supersequence
string longestCommonSubsequence(string text1, string text2)
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
    string ans = "";
    int i = n, j = m;
    while (i != 0 && j != 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            ans += text1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                i = i - 1, j = j;
            else
                i = i, j = j - 1;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
string shortestCommonSupersequence(string str1, string str2)
{
    string lcs = longestCommonSubsequence(str1, str2);
    int n = str1.length(), m = str2.length();
    int i = 0, j = 0, k = 0;
    string ans = "";
    while (k < lcs.length())
    {
        while (i < n && str1[i] != lcs[k])
            ans += str1.substr(i, 1), i++;
        while (j < m && str2[j] != lcs[k])
            ans += str2.substr(j, 1), j++;
        ans += lcs.substr(k, 1);
        k++;
        i++;
        j++;
    }
    if (i < n)
        ans += str1.substr(i, n - i);
    if (j < m)
        ans += str2.substr(j, m - j);
    return ans;
}