//Given an array of integers temperatures represents the daily temperatures, 
//return an array answer such that answer[i] is the number of days 
//you have to wait after the ith day to get a warmer temperature. 
//If there is no future day for which this is possible, keep answer[i] == 0 instead.
#include <bits/stdc++.h>
using namespace std;
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<pair<int, int>> Stack;
    vector<int> ans;
    for (int i = temperatures.size() - 1; i >= 0; i--)
    {
        if (Stack.size() == 0)
        {
            ans.push_back(-1);
        }
        else if (Stack.top().first > temperatures[i])
        {
            ans.push_back(Stack.top().second);
        }
        else
        {
            while (Stack.size() != 0 && Stack.top().first <= temperatures[i])
            {
                Stack.pop();
            }
            if (Stack.size() == 0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(Stack.top().second);
            }
        }
        Stack.push({temperatures[i], i});
    }
    reverse(ans.begin(), ans.end());
    vector<int> answer;
    for (int i = 0; i < temperatures.size(); i++)
    {
        if (ans[i] == -1)
        {
            answer.push_back(0);
        }
        else
        {
            answer.push_back(ans[i] - i );
        }
    }
    return answer;
}
int main()
{
    vector<int> temprature;
    int size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        int temp;
        cin>>temp;
        temprature.push_back(temp);
    }
    vector<int> answer=dailyTemperatures(temprature);
    for(int i=0;i<size;i++)
    {
        cout<<answer[i]<<" ";
    }
}