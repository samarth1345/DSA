//program to produce permutation with case change:particularily for smaller case 
#include<iostream>
using namespace std;
void solve(string ip,string op)
{
    if(ip.length()==0)                  //base condition
    {
        cout<<op<<" ";
        return;
    }
    string op1,op2;
    op1=op+ip[0];
    char help=(ip[0]-32);               //changing from small case to upper case
    op2=op+help;
    ip.erase(0,1);                      //removing first element from ip after taking decision
    solve(ip,op1);
    solve(ip,op2);
}
int main()
{
    string ip;
    cin>>ip;
    solve(ip," ");
    return 0;
}