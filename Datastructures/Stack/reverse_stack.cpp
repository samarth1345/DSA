#include<bits/stdc++.h>
using namespace std;
void InsertAtBottom(stack<int>& Stack,int Element)
{
    if(Stack.empty())
    {
        Stack.push(Element);
        return;
    }
    int store=Stack.top();
    Stack.pop();
    InsertAtBottom(Stack,Element);
    Stack.push(store);
}
void reverse(stack<int>& Stack)
{
    if(Stack.empty())
    {
        return;
    }
    int EleAtTop=Stack.top();
    Stack.pop();
    reverse(Stack);
    InsertAtBottom(Stack,EleAtTop);
}
int main()
{
    stack<int> Stack;
    int n;
    cin>>n;
    int i=n;
    while(i--)
    {
        int temp;
        cin>>temp;
        Stack.push(temp);
    }
    reverse(Stack);
    for(int i=0;i<n;i++)
    {
        cout<<Stack.top()<<endl;
        Stack.pop();
    }
}
