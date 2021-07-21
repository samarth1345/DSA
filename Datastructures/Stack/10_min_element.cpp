//program to calculate minimum element in stack even after poping of elemnts from stack using extra space
#include<bits/stdc++.h>
using namespace std;
stack<int> help;
stack<int> Stack;
void Push(int a)                            //Push function which will further call stack.push()
{
    if(Stack.size()==0 || a<help.top())
    {
        Stack.push(a);
        help.push(a);
    }
    else
    {
        Stack.push(a);
    }
}
void Pop()                                  //Pop function which will further call stack.pop()
{
    if(Stack.top()==help.top())
    {
        help.pop();
    }
    Stack.pop();
}
int minimum()                            //returns minimum element in stack at any point of time
{
    return help.top();
}
int main()
{
    Push(10);
    Push(20);
    Push(5);
    Push(15);
    Pop();
    Pop();
    cout<<minimum();
}