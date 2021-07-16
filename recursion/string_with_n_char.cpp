//Print all possible strings of length k that can be formed from a set of n characters
#include<bits/stdc++.h>
using namespace std;
void solve(string ip,string op,int n)
{
    if(n==0)                            //base condition:when n0. of tring to be formed becomes zero
    {
        cout<<op<<endl;
        return;
    }
    int size=ip.length();
    for(int i=0;i<size;i++)             //as there will be n(size of string) no. of nodes forming at each call
    {
        string op1;
        op1=op+ip[i];
        solve(ip,op1,n-1);            //dealing with one node at a time 
    }
}
int main()
{
    string str;
    int n;
    cin>>n;
    cin>>str;
    solve(str,"",n);
    return 0;
}