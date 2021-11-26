#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int ans=(a+b)/4;
        cout<<min(ans,min(a,b))<<endl;
    }
}