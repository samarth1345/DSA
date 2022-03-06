#include <bits/stdc++.h>
using namespace std;
//Write less code
int dp[101];
int help(vector<int> &nums, int n)
{
    //cout<<n<<" "<<score<<endl;
    if (n < 1)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    return dp[n]=max(nums[n - 1]+help(nums, n - 2), help(nums, n - 1));
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    memset(dp, -1, sizeof(dp));
    cout<<help(nums, nums.size())<<endl;
}