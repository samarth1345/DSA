#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <numeric>
using namespace std;
int dp[201][201][2];
bool evaluate(string s, int start, int end)
{
    bool ans = true ? s[start] == 'T' : false;
    for (int i = start + 1; i <= end; i += 2)
    {
        if (s[i] == '&')
            ans = ans & (true ? s[i + 1] == 'T' : false);
        else if (s[i] == '|')
            ans = ans | (true ? s[i + 1] == 'T' : false);
        else
            ans = ans ^ (true ? s[i + 1] == 'T' : false);
    }
    return ans;
}
int solve(string s, int start, int end, bool need)
{
    if (start > end)
        return 0;
    if (start == end)
        return 1 ? (evaluate(s, start, end) == need) : 0;
    if (dp[start][end][need] != -1)
        return dp[start][end][need];
    int sum = 0;
    for (int i = start + 1; i <= end; i += 2)
    {
        int lt = solve(s, start, i - 1, true);
        int lf = solve(s, start, i - 1, false);
        int rt = solve(s, i + 1, end, true);
        int rf = solve(s, i + 1, end, false);
        ;
        if (need)
        {
            if (s[i] == '|')
                sum += (lt * rt + lt * rf + lf * rt);
            else if (s[i] == '&')
                sum += (lt * rt);
            else
                sum += (lt * rf + lf * rt);
        }
        else
        {
            if (s[i] == '|')
                sum += (lf * rf);
            else if (s[i] == '&')
                sum += (lf * rf + lt * rf + lf * rt);
            else
                sum += (lt * rt + lf * rf);
        }
    }
    return dp[start][end][need] = sum % 1003;
}
int countWays(int N, string S)
{
    // code here
    memset(dp, -1, sizeof(dp));
    return solve(S, 0, N - 1, true);
}
int main()
{
    string s;
    cin >> s;
    cout << countWays(s.length(), s);
}