#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
bool isPalindrome(string &str, int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int solve(string &s, int start, int end)
{
    if (start >= end)
        return 0;
    if (isPalindrome(s, start, end))
        return dp[start][end] = 0;
    if (dp[start][end] != -1)
        return dp[start][end];
    int mn = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        if (isPalindrome(s, start, i))
            mn = min(mn, solve(s, i + 1, end) + 1);
    }
    return dp[start][end] = mn;
}
int minCut(string s)
{
    memset(dp, -1, sizeof(dp));
    return solve(s, 0, s.length() - 1);
}