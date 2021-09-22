#include<iostream>
#include<queue>
using namespace std;

void reverse_queue(queue<int>& queue)
{
    if(queue.empty())
    {
        return;
    }
    int Bottom=queue.front();
    queue.pop();
    reverse_queue(queue);
    queue.push(Bottom);
}
int main()
{
    int size;
    cin>>size;
    queue<int> queue;
    for(int i=1;i<=size;i++)
    {
        int temp;
        cin>>temp;
        queue.push(temp);
    }
    reverse_queue(queue);
    for(int i=1;i<=size;i++)
    {
        cout<<queue.front()<<" ";
        queue.pop();
    }
}