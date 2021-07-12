//program to output balanced paranthesis for a given number
#include<bits/stdc++.h>
using namespace std;
void solve(int open,int closed,string op)
{
    if(open==0 && closed==0)                //open and closed are representing no of open and closed brackets present
    {
        cout<<op<<endl;
        return;
    }
    if(open!=0)                             //condition(for open brackets) concluded from recursion tree
    {
        string op1=op;
        op1.push_back('(');
        solve(open-1,closed,op1);
    }
    if(closed>open)                         //condition(for closed brackets) concluded from recursion tree
    {
        string op2=op;
        op2.push_back(')');
        solve(open,closed-1,op2);
    }
}
int main()
{
    int n;
    cin>>n;
    solve(n,n,"");
    return 0;
}