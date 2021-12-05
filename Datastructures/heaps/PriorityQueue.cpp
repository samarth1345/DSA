#include<iostream>
#include"PriorityQueue.h"
using namespace std;
int main()
{
    PriorityQueue *obj=new PriorityQueue(1);
    obj->Insert(5);
    obj->Insert(10);
    obj->Insert(2);
    obj->Insert(10);
    obj->Insert(9);
    obj->Insert(-1);
    obj->display();
}