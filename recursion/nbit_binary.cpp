//Given a positive integer N, the task is to find all the N bit binary numbers having 
//more than or equal 1’s than 0’s for any prefix of the number.
#include<bits/stdc++.h>
#include<vector>
using namespace std;
void solve(string op,int n,int one,int zero,vector<string>& v)
{
    if(n==0)                               //base condition
    {
        v.push_back(op);                    //using a vector to store string and print in decreasing order
        return;
    }
    if(one<=zero)                         //decision from recursion tree
    {
        string op1;
        op1=op+"1";
        solve(op1,n-1,one+1,zero,v);
    }
    else                                 //decision from recursion tree
    {
        string op1,op2;
        op1=op+"0";
        op2=op+"1";
        solve(op1,n-1,one,zero+1,v);
        solve(op2,n-1,one+1,zero,v);
    }
}
int main()                            
{
    int n;
    cin>>n;
    vector<string> v;
    solve("",n,0,0,v);
    for(int i=v.size()-1;i>=0;i--)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}

