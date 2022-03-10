#include <bits/stdc++.h>
using namespace std;
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
int main()
{
    string a, b;
    cin >> a >> b;
    cout << longestCommonSubsequence(a, b);
}