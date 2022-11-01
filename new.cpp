#include <bits/stdc++.h>
#define endl "\n"
#define int long long int
using namespace std;
const int Mod = 1000000007;
int power(int x, int p)
{
    if (p == 0)
        return 1;
    int ans = power((x * x) % Mod, p / 2) % Mod;
    if (p & 1)
        return (ans * x) % Mod;
    else
        return ans % Mod;
}
int max(vector<int> &a)
{
    int t = LONG_MIN;
    for (int i : a)
        t = max(t, i);
    return t;
}
int min(vector<int> &a)
{
    int t = LONG_MAX;
    for (int i : a)
        t = min(t, i);
    return t;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> y[i];
    vector<int> diff(n);
    for (int i = 0; i < n; i++)
    {
        diff[i] = (+y[i] - x[i]);
    }
    sort(diff.begin(), diff.end());
    int left = -1, right = -1;
    for (int i = 0; i < n; i++)
    {
        if (diff[i] >= 0)
        {
            right = i;
            left = i - 1;
            break;
        }
    }
    // cout<<left<<" "<<right<<endl;
    if (right == -1)
    {
        cout << "0" << endl;
        return;
    }
    // there is no point of adding third element to group
    // that small negative may help other bigger positive
    int count = 0;
    while (left >= 0 && right < n)
    {
        if (diff[left] + diff[right] >= 0)
        {
            count++;
            left--;
            right++;
        }
        else
        {
            if (right + 1 >= n)
                break;
            count++;
            right += 2;
        }
    }
    if (right < n)
    {
        count += (n - right) / 2;
    }
    cout << count << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}