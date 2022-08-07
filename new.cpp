#include <bits/stdc++.h>
#define endl "\n"
#define int long long int
using namespace std;
int dp[100001];
int help(vector<int> temp, int i)
{
    if (i == temp.size() - 1)
        return 1;
    if (dp[i] != -1)
        return dp[i];
    int ans = 0;
    for (int j = i + 1; j < temp.size(); j++)
    {
        if (temp[j] % temp[i] == 0)
            ans += help(temp, j);
    }
    return dp[i] = ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> temp;
    for (int i = 1; i <= sqrt(n); i++)
    {

        if (n % i == 0)
        {
            temp.push_back(i);
            if ((n / i) != i)
                temp.push_back(n / i);
        }
    }
    sort(temp.begin(), temp.end());
    // for (auto i : temp)
    //     cout << i << endl;
    memset(dp, -1, sizeof(dp));
    cout << help(temp, 0) << " " << endl;
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}