#include <iostream>
#include "DoublyLinkedList.cpp"
using namespace std;
int main()
{
    Doublyll obj;
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);
    obj.print();
    obj.insertion(20,25);
    obj.print();

    obj.Reverse_iter();
    obj.print();
}
