#include<iostream>
#include<stack>
using namespace std;
//function to insert at bottom of stack recursively
void InsertatBottom(stack<int>& Stack,int bottom)
{
    if(Stack.empty())
    {
        Stack.push(bottom);
        return;
    }
    int store=Stack.top();
    Stack.pop();
    InsertatBottom(Stack,bottom);
    Stack.push(store);
}

void reverse_stack(stack<int>& Stack)
{
    if(Stack.empty())
    {
        return;
    }
    int Bottom=Stack.top();
    Stack.pop();
    reverse_stack(Stack);
    InsertatBottom(Stack,Bottom);
}
int main()
{
    int size;
    cin>>size;
    stack<int> Stack;
    for(int i=1;i<=size;i++)
    {
        int temp;
        cin>>temp;
        Stack.push(temp);
    }
    reverse_stack(Stack);
    for(int i=1;i<=size;i++)
    {
        cout<<Stack.top()<<" ";
        Stack.pop();
    }
}