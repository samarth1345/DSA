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
        else if(Stack.size()>0 && Stack.top()>=v[i])
        {
            ans.push_back(Stack.top());
        }
        else
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
    reverse(ans.begin(),ans.end());
    return ans;
}
