//Implement queue using LL and its operations in O(1)
#include <iostream>
using namespace std;
template <typename T>
class queue
{
    queue *head;
    queue *next;
    queue *tail;
    T data;
    int size;
public:
    queue()
    {
        head = NULL;
        next = NULL;
        size = 0;
    }
    //keeping the first came element at head
    //and last came element at tail
    void push(T value)
    {
        queue *newhead = new queue();
        newhead->data = value;
        size++;
        if (head == NULL)
        {
            head=newhead;
            tail = head;
        }
        else
        {
            tail->next = newhead;
            tail = newhead;
        }
    }
    void pop()
    {
        size--;
        head = head->next;
    }
    T front()
    {
        return head->data;
    }
    int getsize()
    {
        return size;
    }
    bool isempty()
    {
        return size==0;
    }
};
int main()
{
    queue<int> que;
    que.push(20);
    que.push(30);
    que.pop();
}