#include<iostream>
using namespace std;
int solve(int m,int n)
{
    if(m==0)
    {
        return n+1;
    }
    if(m>0 && n==0)
    {
        return solve(m-1,1);
    }
    else if(m>0 && n>0)
    {
        return solve(m-1,solve(m,n-1));
    }
    return 0;
}
int main()
{
    cout<<solve(2,0);
}