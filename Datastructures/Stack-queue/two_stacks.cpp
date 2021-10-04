#include <iostream>
using namespace std;
class twostack
{
    int top1, top2;
    int capacity;
    int *arr;
    int size;

public:
    twostack(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        top1 = -1;
        top2 = capacity;
        size = 0;
    }
    void push_1(int value)
    {
        if (size < capacity)
        {
            top1++;
            arr[top1] = value;
            size++;
        }
    }
    void push_2(int value)
    {
        if (size < capacity)
        {
            top2--;
            arr[top2] = value;
            size++;
        }
    }
    void pop_1()
    {
        size--;
        arr[top1] = -1;
        top1--;
    }
    void pop_2()
    {
        size--;
        arr[top2] = -1;
        top2++;
    }
    int top_1()
    {
        if (top1 >= 0)
        {
            return arr[top1];
        }
        return -1;
    }
    int top_2()
    {
        if (top2 < capacity)
        {
            return arr[top2];
        }
        return -1;
    }
    int getsize()
    {
        return size;
    }
};
int main()
{
    twostack obj(10);
    obj.push_1(10);
    obj.push_2(20);
    obj.push_1(10);
    obj.push_2(20);
    obj.push_1(10);
    obj.push_2(20);
    obj.push_1(10);
    obj.push_2(20);
    obj.push_1(10);
    obj.push_2(20);
    cout << obj.top_1() << endl
         << obj.top_2() << endl
         << obj.getsize();
}