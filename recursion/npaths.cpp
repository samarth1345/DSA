//Count ways to reach the nth stair using step 1, 2 or 3
#include<bits/stdc++.h>
using namespace std;
void solve(int n,int m,int& count)
{
    if(m>=n)
    {
        if(m==n)
        {
            count+=1;
        }
        return;
    }
    solve(n,m+1,count);
    solve(n,m+2,count);
    solve(n,m+3,count);
}
int main()
{
    int n,count;
    cin>>n;
    count=0;
    solve(n,0,count);
    cout<<count;
    return 0;
}