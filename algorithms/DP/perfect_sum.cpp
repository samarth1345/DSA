#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
int dp[1000][1000];
int mod = 1e9 + 7;
int help(vector<int> arr, int n, int sum)
{
    if (n == 0)
    {
        //this is a important case which i was missing, in this we have to take care 
        //if sum==0 and arr[n] is alse 0, we have two choices there which can get us 
        //required result.
        if (sum == 0 && arr[0] == 0)
            return 2;
        if (sum == 0 || arr[0] == sum)
            return 1;
        return 0;
    }
    if (dp[n][sum] != -1)
        return dp[n][sum] % mod;
    if (arr[n] <= sum)
    {
        return dp[n][sum] = (help(arr, n - 1, sum - arr[n]) + help(arr, n - 1, sum)) % mod;
    }
    return dp[n][sum] = help(arr, n - 1, sum) % mod;
}
int perfectSum(vector<int> arr, int n, int sum)
{
    memset(dp, -1, sizeof(dp));
    return help(arr, n - 1, sum) % mod;
}
int main()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> arrn;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        arrn.push_back(t);
    }
    cout << perfectSum(arrn, n, sum);
}