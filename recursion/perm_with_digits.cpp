//program to produce permutation with case change including digits
#include<bits/stdc++.h>
using namespace std;
void solve(string ip,string op)
{
    if(ip.length()==0)                  //base condition
    {
        cout<<op<<" ";
        return;
    }
    string op1,op2;
    if(isalpha(ip[0]))                 //two choices if a alphabet
    {
        op1=op2=op;
        op1.push_back(toupper(ip[0]));
        op2.push_back(tolower(ip[0]));
        ip.erase(0,1);                     
        solve(ip,op1);
        solve(ip,op2);
    }
    else                              //one choice if digit
    {
        op1=op+ip[0];
        ip.erase(0,1);   
        solve(ip,op1);
    }
}
int main()
{
    string ip;
    cin>>ip;
    solve(ip," ");
    return 0;
}