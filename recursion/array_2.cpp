//Sum triangle from array
#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> v)
{
    if(v.size()==1)
    {
        return ;
    }
    for(int i=0;i<v.size();i++)
    {
        v[i]=v[i]+v[i+1];
    }
    v.pop_back();
    solve(v);
    int n=v.size();
    while(n!=0)
    {
        cout<<v[v.size()-n]<<"  ";
        n--;
    }
    cout<<endl;
}
int main()
{
    vector<int> v;
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    solve(v);
    int n=v.size();
    while(n!=0)
    {
        cout<<v[v.size()-n]<<"  ";
        n--;
    }
    return 0;
}