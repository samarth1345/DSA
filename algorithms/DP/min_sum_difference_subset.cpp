#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include<cstring>
#include<numeric>
using namespace std;
bool dp[1000][10000];
void help(int N, vector<int> arr, int sum)
{
    for (int i = 0; i <= N; i++)
        dp[i][0] = true;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j - arr[i - 1] >= 0)
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] | dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
}
int minimumDifference(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
    help(n, nums, sum);
    vector<int> ans;
    for (int i = 0; i <= sum / 2; i++)
    {
        if (dp[n][i] == 1)
            ans.push_back(i);
    }
    int mini = sum, s = ans.size();
    for (int i = 0; i < s; i++)
    {
        mini = min(mini, sum - 2 * ans[i]);
    }
    return mini;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<minimumDifference(arr)<<endl;
    }
}