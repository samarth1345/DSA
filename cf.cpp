#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> A,pair<int,int> B)
{
    return A.first<B.first;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n],b[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)
        {
            v[i].first=a[i];
            v[i].second=b[i];
        }
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<n;i++)
        {
            if(v[i].first<=k)
                k+=v[i].second;
            else
                break;
        }
        cout<<k<<endl;
    }
}