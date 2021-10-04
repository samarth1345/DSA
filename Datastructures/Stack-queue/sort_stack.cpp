#include<iostream>
#include<stack>
using namespace std;
void insert(stack<int>& s,int element)
{
    if(s.size()==0||element>=s.top())
    {
        s.push(element);
        return;
    }
    int store=s.top();
    s.pop();
    insert(s,element);
    s.push(store);
}
void sort(stack<int>& s)
{
    if(s.size()==0 || s.size()==1)
    {
        return;
    }
    int element=s.top();
    s.pop();
    sort(s);
    insert(s,element);
}
int main()
{
    int size;
    stack<int> s;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        int temp;
        cin>>temp;
        s.push(temp);
    }
    sort(s);
    for(int i=0;i<size;i++)
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}