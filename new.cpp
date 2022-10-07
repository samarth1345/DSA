//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int dp[1001][1001];
    int mx = 0;
    int help(string s1, string s2, int n, int m, int count)
    {
        if (n == 0 || m == 0)
            return 0;
        if (s1[n - 1] == s2[m - 1])
            return help(s1, s2, n - 1, m - 1, count + 1);
        return max({count, help(s1, s2, n - 1, m, 0), help(s1, s2, n, m - 1, 0)});
    }
    int longestCommonSubstr(string s1, string s2, int n, int m)
    {
        return help(s1, s2, n, m, 0);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2, n, m) << endl;
    }
}