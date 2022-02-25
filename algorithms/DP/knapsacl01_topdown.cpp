#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int dp[1001][1001];
int knapsack(vector<int> wt,vector<int> val,int W,int n)
{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
        }
    }  
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}
int main()
{
    int n,w;
    cin>>n>>w;
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