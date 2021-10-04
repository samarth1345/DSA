#include<iostream>
using namespace std;
template<typename T>
class stack{
    stack* head;
    stack* next;
    T data;
    int Size;
    public:
    stack()
    {
        Size=0;
        head=NULL;
        next=NULL;
    }
    void push(T data)
    {
        Size++;
        stack* newhead=new stack();
        newhead->data=data;
        if(head==NULL)
        {
            head=newhead;
        }
        else
        {
            newhead->next=head;
            head=newhead;
        }
    }
    T top()
    {
        return head->data;
    }
    void pop()
    {
        Size--;
        head=head->next;
    }
    int size()
    {
        return Size;
    }
    bool empty()
    {
        if(head==NULL)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    
    stack<int> Stack;
    cout<<Stack.empty()<<endl;
    Stack.push(10);
    Stack.push(20);
    cout<<Stack.top()<<endl;
    Stack.pop();
    cout<<Stack.top()<<endl;
    
}