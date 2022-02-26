#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include<cstring>
#include<numeric>
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
//this is same as perfect sum, we find sum by mathematical calculation
//i.e sum(subset1)-sum(subset2)=diff
//    sum(subset1)+sum(subset2)=totalsum
//    2(sum(subset1))=(diff+totalsum)
int minimumDifference(vector<int> &nums,int diff)
{
    memset(dp, -1, sizeof(dp));
    int sum=(diff+accumulate(nums.begin(),nums.end(),0))/2;
    return help(nums, nums.size() - 1, sum) % mod;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,diff;
        cin>>n>>diff;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<minimumDifference(arr,diff)<<endl;
    }
}