#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;
int dp[1001][1001];
int knapsack(vector<int> wt,vector<int> val,int w,int n)
{
    if(w==0 || n==0)
        return 0;
    if(dp[w][n-1]!=-1)
        return dp[w][n-1];
    if(wt[n-1]<=w)
        return dp[w][n-1]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    return knapsack(wt,val,w,n-1);
}
int main()
{
    int n,w;
    cin>>n>>w;
    memset(dp,-1,sizeof(dp));
    vector<int> wt,val;
    for(int i=0;i<n;i++)
    {
        int t; cin>>t;
        wt.push_back(t);
    }
    for(int i=0;i<n;i++)
    {
        int t; cin>>t;
        val.push_back(t);
    }
    cout<<knapsack(wt,val,w,n);
}