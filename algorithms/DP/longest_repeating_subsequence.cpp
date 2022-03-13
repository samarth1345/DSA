#include <bits/stdc++.h>
using namespace std;
// Given a string str, find the length of the longest repeating subsequence
// such that it can be found twice in the given string. The two identified subsequences
// A and B can use the same ith character from string str
// if and only if that ith character has different indices in A and B.
int longestRepeatingSubsequence(string text1, string text2)
{
    int dp[1001][1001];
    int n = text1.length(), m = text2.length();
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if ((text1[i - 1] == text2[j - 1]) && (i != j))
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
int main()
{
    string a;
    cin >> a;
    cout << longestRepeatingSubsequence(a, a) << endl;
}