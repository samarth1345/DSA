#include <bits/stdc++.h>
using namespace std;
void reversek(queue<int> &q, int k)
{
    //stack has to be used but instead of queue
    //we can push pop for n-k times after inserting elements 
    //in queue from stack 
    queue<int> q1;
    stack<int> s1;
    for(int i=1;i<=k;i++)
    {
        s1.push(q.front());
        q.pop();
    }
    while(!q.empty())
    {
        q1.push(q.front());
        q.pop();
    }
    for(int i=1;i<=k;i++)
    {
        q.push(s1.top());
        s1.pop();
    }
    while(!q1.empty())
    {
        q.push(q1.front());
        q1.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    reversek(q, 3);
    while (q.size() > 0)
    {
        cout << q.front() << " ";
        q.pop();
    }
}