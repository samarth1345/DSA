//next greater element in circular array
#include<bits/stdc++.h>
#include<stack>
using namespace std;
vector<int> solve(vector<int> nums)
{
    vector<int> ans;
    stack<int> Stack;
    //push all elements before hand to behave as circular array
    for(int i=nums.size()-1;i>=0;i--)
    {
        Stack.push(nums[i]);
    }
    for(int i=nums.size()-1;i>=0;i--)
    {
        if(Stack.size()==0)
        {
            ans.push_back(-1);
        }
        else if(Stack.size()>0 && Stack.top()>nums[i])
        {
            ans.push_back(Stack.top());
        }
        else if(Stack.size()>0 && Stack.top()<=nums[i])
        {
            while(Stack.size()!=0 && Stack.top()<=nums[i])
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
        Stack.push(nums[i]);
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