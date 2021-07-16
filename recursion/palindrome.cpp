#include<bits/stdc++.h>
using namespace std;
void solve(string str,bool& flag)
{
    int size=str.length();
    if(size==0)
    {
        cout<<"palindrome"<<endl;
        flag=true;
        return;
    }
    if(str[0]==str[size-1])
    {
        str.erase(size-1,1);
        str.erase(0,1);
        solve(str,flag);
    }
    else
    {
        flag=false;
    }
}
int main()
{
    string str;
    cin>>str;
    bool flag=false;
    solve(str,flag);
    if(!flag)
    {
        cout<<"Not a plaindrome"<<endl;
    }
}