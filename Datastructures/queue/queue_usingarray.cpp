//Implement queue using array and all operations in O(1)
#include <iostream>
using namespace std;
template <typename T>
class queue
{
    T *data = NULL;
    int nextindex;
    int firstindex;
    int Size;
    int capacity;

public:
    queue(int capacity)
    {
        this->capacity = capacity;
        data = new T[capacity];
        firstindex = -1;
        nextindex = 0;
        Size = 0;
    }
    //in dequeue we are movinf firstindex but memory before 
    //firstindex is getting under utilised so when nextindex cannot 
    //be moved further we will move it to 0 index as that memory
    //is vacant
    void enqueue(T value)
    {
        if (Size <= capacity)
        {
            if (nextindex >= capacity)
            {
                nextindex = 0;
            }
            Size++;
            data[nextindex] = value;
            if (firstindex == -1)
            {
                firstindex++;
            }
            nextindex++;
        }
    }
    T front()
    {
        return data[firstindex];
    }
    //in this function we will just move firstindex by 1
    //and make the data at prev. firstindex as -1
    void dequeue()
    {
        if (Size > 0)
        {
            data[firstindex]=-1;
            if (firstindex >= capacity - 1)
            {
                firstindex = 0;
            }
            else
            {
                firstindex++;
            }
            Size--;
        }
    }
    int size()
    {
        return Size;
    }
    bool empty()
    {
        if(Size>0)
        {
            return false;
        }
        return true;
    }
};
int main()
{
    queue<float> Queue(5);
    Queue.enqueue(10.25);
    Queue.enqueue(20.25);
    Queue.enqueue(30.25);
    Queue.dequeue();
    Queue.dequeue();
    Queue.dequeue();
    Queue.enqueue(40.25);
    Queue.enqueue(50.25);
    Queue.enqueue(60.25);
    Queue.dequeue();
    Queue.dequeue();
    Queue.enqueue(50.25);
    Queue.dequeue();
    Queue.dequeue();
    Queue.enqueue(10.25);
    Queue.enqueue(20.25);
    Queue.enqueue(30.25);
    Queue.enqueue(50.25);
    Queue.enqueue(60.25);
    Queue.dequeue();
    Queue.dequeue();
    Queue.dequeue();
    Queue.dequeue();
    Queue.dequeue();
    cout << Queue.front();
}