#include<bits/stdc++.h>
using namespace std;
void solve(string op,int k)
{
    if(k==0)
    {
        cout<<op<<endl;
        return;
    }
    if(op.back()=='1')
    {
        string op1;
        op1=op+"0";
        solve(op1,k-1);
    }
    else
    {
        string op1,op2;
        op1=op+"0";
        op2=op+"1";
        solve(op1,k-1);
        solve(op2,k-1);
    }
}
int main()
{
    int k;
    cin>>k;
    solve("",k);
    return 0;
}