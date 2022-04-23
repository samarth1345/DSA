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
        //important to understand: if the place at which we are partioning is 
        //not palindrome itself,we are not gonna partition there we will partition
        //only when first half is palindrome and if it is not it has been taken care 
        //by dividing into smaller partition before reaching at this point.
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