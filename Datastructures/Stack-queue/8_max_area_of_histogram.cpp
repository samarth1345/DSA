//max area of a histogram

#include<bits/stdc++.h>
using namespace std;
/************************************/
//function to find nearest greatest element to right
vector<int> NSR(vector<int> v)
{
    vector<int> right;
    stack<pair<int,int>> Stack;
    for(int i=v.size()-1;i>=0;i--)
    {
        if(Stack.size()==0)
        {
            right.push_back(v.size());
        }
        else if(v[i]>Stack.top().first)
        {
            right.push_back(Stack.top().second);
        }
        else if(v[i]<=Stack.top().first)
        {
            while(Stack.size()!=0 && v[i]<=Stack.top().first)
            {
                Stack.pop();
            }
            if(Stack.size()==0)
            {
                right.push_back(v.size());
            }
            else
            {
                right.push_back(Stack.top().second);
            }
        }
        Stack.push({v[i],i});
    }
    reverse(right.begin(),right.end());
    return right;
}
/************************************/
//function to find nearest greatest element to right
vector<int> NSL(vector<int> v)
{
    vector<int> left;
    stack<pair<int,int>> Stack;
    for(int i=0;i<v.size();i++)
    {
        if(Stack.size()==0)
        {
            left.push_back(-1);
        }
        else if(v[i]>Stack.top().first)
        {
            left.push_back(Stack.top().second);
        }
        else if(v[i]<=Stack.top().first)
        {
            while(Stack.size()!=0 && v[i]<=Stack.top().first)
            {
                Stack.pop();
            }
            if(Stack.size()==0)
            {
                left.push_back(-1);
            }
            else
            {
                left.push_back(Stack.top().second);
            }
        }
        Stack.push({v[i],i});
    }
    return left;
}
/*******************************************************/
vector<int> solve(vector<int> v)
{
    vector<int> right;
    vector<int> left;
    right=NSR(v);
    left=NSL(v);
    vector<int> width;
    for(int i=0;i<v.size();i++)
    {
        width.push_back(right[i]-left[i]-1);
    }
    return width;
}
/******************************************************/
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
    vector<int> width;
    width=solve(v);
    int max=(width[0]*v[0]);
   for(int i=1;i<n;i++)
    {
        if((width[i]*v[i])>max)
        {
            max=width[i]*v[i];
        }
    }
    cout<<max;
    return 0;
}