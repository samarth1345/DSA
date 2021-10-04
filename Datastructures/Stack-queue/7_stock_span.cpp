#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> v)
{
    vector<int> ans;
    stack<pair<int,int>> Stack;         //for storing pair of values in stack: use of first and and second to access value
    for(int i=0;i<v.size();i++)
    {
        if(Stack.size()==0)
        {
            ans.push_back(-1);
        }
        else if(Stack.size()>0 && Stack.top().first>v[i])
        {
            ans.push_back(Stack.top().second);
        }
        else if(Stack.size()>0 && Stack.top().first<v[i])
        {
            while(Stack.size()!=0 && Stack.top().first<v[i])
            {
                Stack.pop();
            }
            if(Stack.size()==0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(Stack.top().second);
            }
        }
        Stack.push({v[i],i});
    }
    for(int i=0;i<ans.size();i++)
    {
        ans[i]=i-ans[i];
    }
    return ans;
}
int main()
{
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    vector<int> ans;
    ans=solve(v);
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}