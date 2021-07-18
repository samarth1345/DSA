//Print all possible combinations of r elements in a given array of size n
#include<bits/stdc++.h>
using namespace std;
void solve(string ip,string op,int n)
{
    if(op.length()==n)
    {
        cout<<op<<endl;
        return;
    }
    int size=ip.length();
    for(int i=0;i<size;i++)
    {
        string op1;
        string op2=ip.substr(0,1);
        op1=op+op2;
        ip.erase(0,1);
        solve(ip,op1,n);
    }
}
int main()
{
    int n,r;
    cin>>n>>r;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ostringstream os;
    for(int i:arr)
    {
        os<<i;
    }
    string str(os.str());
    solve(str,"",r);
}