//program to calculate minimum element in stack even after poping of elemnts from stack in o(1) space
#include<bits/stdc++.h>
using namespace std;
stack<int> Stack;
int temp;
void Push(int a)                            //Push function which will further call stack.push()
{
    if(Stack.size()==0)
    {
        Stack.push(a);
        temp=a;
    }
    else if(temp>a)
    {
        Stack.push(2*a-temp);                //this is to store previous minimum element in case minimum element is poped
        temp=a; 
    }
    else
    {
        Stack.push(a);
    }
}
void Pop()                                  //Pop function which will further call stack.pop()
{
    if(Stack.top()<temp)
    {
        temp=(2*temp-Stack.top());
    }
    Stack.pop();
}
void minimum()                            //returns minimum element in stack at any point of time
{
    cout<<temp;
}
int main()
{
    Push(10);
    Push(20);
    Push(5);
    Push(15);
    Pop();
    Pop();
    minimum();
}