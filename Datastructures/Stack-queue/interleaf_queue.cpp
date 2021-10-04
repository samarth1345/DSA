#include<bits/stdc++.h>
using namespace std;
void interLeaveQueue(queue < int > & q) {
    // Write your code here.
    int arr[q.size()];
    int i=0;
    while(!q.empty())
    {
        arr[i]=q.front();
        q.pop();
        i++;
    }
    for(int j=0;j<i/2;j++)
    {
        q.push(arr[j]);
        q.push(arr[j+(i/2)]);
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
    q.push(6);
    interLeaveQueue(q);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}