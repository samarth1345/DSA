#include<bits/stdc++.h>
using namespace std;
void solve(string ip,string op,int j)
{
    if(j==ip.length())
    {
        cout<<op;
        return;
    }
    if(ip[j]!=ip[j+1])
    {
        op+=ip[j];
    }
    solve(ip,op,j+1);
}
int main()
{
    string ip;
    cin>>ip;
    solve(ip,"",0);
}