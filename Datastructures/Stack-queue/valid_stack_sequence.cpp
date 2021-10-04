#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//logic: push elements of pushed and pop if top matches popped[j]
//at end if stack is empty we know operations were successful
bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> Stack;
    int j = 0, i = 0;
    while (i < pushed.size())
    {
        Stack.push(pushed[i]);
        i++;
        while (Stack.size() > 0 && Stack.top() == popped[j])
        {
            Stack.pop();
            j++;
        }
    }
    if (Stack.empty())
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<int> pushed,popped;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        pushed.push_back(temp);
    }
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        popped.push_back(temp);
    }
    cout<<validateStackSequences(pushed,popped);
}