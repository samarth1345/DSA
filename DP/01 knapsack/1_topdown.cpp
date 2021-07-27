#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,twt;
    cin>>n>>twt;
    int wt[n],val[n];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }
    int dp[n+1][twt+1];
    //initalisation from base condition
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<twt+1;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<twt+1;j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j]=max(val[i]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][twt];
    return 0;
}