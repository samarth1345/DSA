#include <iostream>
#include "circularLinkedlist.cpp"
using namespace std;
int main()
{
    Circularll obj;
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);
    obj.push(50);
    obj.print();
    obj.Reverse_iter();
    obj.print();
    obj.insertion(50,25);
    obj.print();
}
