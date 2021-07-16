#include<bits/stdc++.h>
using namespace std;
bool check(string str)
{
    int n1,n2,n3;
    string str1,str2,str3;
    str1=str[0]; str2=str[1]; str3=str[2];
    n1=stoi(str1); 
    n2=stoi(str2); 
    n3=stoi(str3); 
    if(n3==(n2+n1))
    {
        return true;
    }
    return false;

}
void solve(string str,bool flag)
{
    if(str.size()<3)
    {
        return;
    }
    flag=check(str);
    if(flag)
    {
        cout<<str[0]<<" + "<<str[1]<<" = "<<str[2]<<endl;
    }
    str.erase(0,1);
    solve(str,flag);
}
int main()
{
    string str;
    cin>>str;
    solve(str,false);
    return 0;
}
