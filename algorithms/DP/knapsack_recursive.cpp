#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
//recursive  approach to 01 knapsack problem
int getmaxprofit(vector<int> wt,vector<int> val,int w,int n)
{
    if(w==0 || n==0)
        return 0;
    if(wt[n-1]<=w)
        return max(val[n-1]+getmaxprofit(wt,val,w-wt[n-1],n-1),getmaxprofit(wt,val,w,n-1));
    return getmaxprofit(wt,val,w,n-1);
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
    cout<<getmaxprofit(wt,val,w,n);
}