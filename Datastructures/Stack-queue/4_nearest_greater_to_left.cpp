#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> v)
{
    vector<int> ans;
    stack<int> Stack;
    for(int i=0;i<v.size();i++)
    {
        if(Stack.size()==0)
        {
            ans.push_back(-1);
        }
        else if(v[i]<=Stack.top())
        {
            ans.push_back(Stack.top());
        }
        else
        {
            while(Stack.size()!=0 && v[i]>Stack.top())
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
