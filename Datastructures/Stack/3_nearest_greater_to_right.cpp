#include<bits/stdc++.h>
#include<stack>
using namespace std;
vector<int> solve(vector<int> v)
{
    vector<int> ans;
    stack<int> Stack;
    for(int i=v.size()-1;i>=0;i--)
    {
        if(Stack.size()==0)
        {
            ans.push_back(-1);
        }
        else if(Stack.size()>0 && Stack.top()>v[i])
        {
            ans.push_back(Stack.top());
        }
        else if(Stack.size()>0 && Stack.top()<v[i])
        {
            while(Stack.size()!=0 && Stack.top()<v[i])
            {
                Stack.pop();
            }
            if(Stack.size()==0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(Stack.top());
            }
        }
        Stack.push(v[i]);
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
    vector<int> ans=solve(v);
    reverse(ans.begin(),ans.end());
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}