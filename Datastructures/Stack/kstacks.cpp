//Implemented k stacks in array
#include <iostream>
using namespace std;
class stack
{
    int *arr, *next, *top;
    int freetop;
    int size;
    int capacity;

public:
    stack(int capacity, int k)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        next = new int[capacity];
        top = new int[10];
        size = 0;
        freetop = 0;
        for (int i = 0; i < k; i++)
        {
            top[i] = -1;
        }
        for (int i = 0; i < capacity; i++)
        {
            next[i] = -1;
            arr[i] = -1;
        }
    }
    void push(int value, int stack_no)
    {
        if (size < capacity)
        {
            if (arr[freetop] != -1)
            {
                while (arr[freetop] != -1 && freetop<capacity)
                {
                    freetop++;
                }
            }
            arr[freetop] = value;
            next[freetop] = top[stack_no];
            top[stack_no] = freetop;
            freetop++;
            size++;
        }
    }
    int getTop(int stack_no)
    {
        if (top[stack_no] != -1)
        {
            return arr[top[stack_no]];
        }
        return -1;
    }
    void pop(int stack_no)
    {
        int top_pos = top[stack_no];
        if (top_pos != -1)
        {
            arr[top_pos] = -1;
            if(top_pos<freetop)
            {
                freetop = top_pos;
            }
            top[stack_no] = next[top_pos];
            size--;
        }
    }
    int getsize()
    {
        return size;
    }
};
int main()
{
    stack Stack(10, 4);
    Stack.push(10, 0);
    Stack.push(20, 0);
    Stack.push(30, 0);
    Stack.push(40, 1);
    Stack.push(50, 1);
    Stack.push(60, 1);
    Stack.push(70, 2);
    Stack.push(80, 3);
    Stack.push(90, 3);
    Stack.push(100, 3);
    Stack.pop(0);
    Stack.pop(3);
    Stack.push(7,3);
    Stack.push(17,3);
    cout<<Stack.getTop(3);
}