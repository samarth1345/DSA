//this is the recursive implementation of 01 knapsack problem
#include<bits/stdc++.h>
using namespace std;
int knapsack(int wt[],int val[],int twt,int n)
{
    if(n==0 || twt==0)
    {
        return 0;
    }
    if(wt[n-1]<=twt)
    {
        return max(val[n-1]+knapsack(wt,val,twt-wt[n-1],n-1), knapsack(wt,val,twt,n-1));   //returning max of two choices i.e include wt[n-1] or !
    }
    else
    {
        return knapsack(wt,val,twt,n-1);            //here only one choice is possible i.e we cannot include wt[n-1]
    }
}
int main()
{
    int twt,n;
    cin>>n>>twt;
    int wt[n],val[n];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }
    cout<<knapsack(wt,val,twt,n);
    return 0;
}
