#include<bits/stdc++.h>
using namespace std;
int check(int j,vector<int> arr)
{
    while(arr.size())
    {
        if(j<=arr[0])
        {
            return arr[0];
        }
        else
        {
        arr.erase(arr.begin());
        }
    }
    return -1;
}
void solve(vector<int> op,vector<int> ip1,vector<int> ip2)
{
    if(op.size()%2==0)
    {
        for(int i=0;i<op.size();i++)
        {
            cout<<op[i]<<" ";
        }
        cout<<endl;
    }
    if(ip1.size()<=1)
    {
        return;
    }
    int help=check(ip1[0],ip2);
    if(help!=-1)
    {
        op.push_back(help);
    }
}
int main()
{

}
