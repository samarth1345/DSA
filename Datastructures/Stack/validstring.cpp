#include <bits/stdc++.h>
using namespace std;
int findMaxLen(string s)
{
    // code here
    stack<pair<char, int>> Stack;
    int arr[s.length()] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            Stack.push({'(', i});
        }
        else if (s[i] == ')' && Stack.size()>0 && Stack.top().first == '(')
        {
            arr[i] = 1;
            arr[Stack.top().second] = 1;
            Stack.pop();
        }
    }
    int max = 0;
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if(arr[i]==1)
        {
            if(i==0)
            {
                count++;
            }
            else
            {
                if(arr[i-1]==1)
                {
                    count++;
                }
                else
                {
                    count=1;
                }
            }
        }
        if(count>max)
        {
            max=count;
        }
    }
    return max;
}
int main()
{
    string s;
    cin>>s;
    cout<<findMaxLen(s);
}