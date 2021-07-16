//program to concatenate two string char by char.
#include<iostream>
using namespace std;
void solve(string p,string q,string r)
{
    if(p.length()==0)
    {
        cout<<r;
        return;
    }
    r=r+p[0]+q[0];
    p.erase(0,1);
    q.erase(0,1);
    solve(p,q,r);
}
int main()
{
    string p,q,r;
    cin>>p>>q;
    r="";
    solve(p,q,r);
    return 0;
}
